/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:58:30 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/12 15:40:55 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	has_movement(bool *mov)
{
	int n = 0;
	while (n <= 3)
	{
		if (mov[n] == true)
			return true;
		n++;
	}
	return false;
}

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	if (has_movement(data->hooks) == true)
		ft_movement(data);
	create_image(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	display_fps(data);
	return 0;
}

static int mlx_data_init(t_data *data)
{
	if ((data->mlx = mlx_init()) == NULL)
		return (0);
	mlx_get_screen_size(data->mlx, &data->img_w, &data->img_h);
	data->img_w /= 2;
	data->img_h /= 2;
	if ((data->mlx_win = mlx_new_window(data->mlx, data->img_w, data->img_h, "My CUB3D!")) == NULL)
		return (0);
	ft_hooks(data);
	mlx_do_key_autorepeatoff(data->mlx);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (1);
}

int convert_orientation(t_data *data, char pos)
{
	data->dirX = 0;
	data->dirY = 0;
	if (pos == 'N')
		data->dirX = 1;
	if (pos == 'S')
		data->dirX = -1;
	if (pos == 'W')
		data->dirY = -1;
	if (pos == 'E')
		data->dirY = 1;
}

int main(int argc, char *argv[])
{
	t_data	data;
	t_map	map;
	bool	i;
	data.map = &map;

	if (parsing_map(argc, argv, &map) == 1)
		return (1);
	data.worldMap = map.int_map;

	data.posX = map.p_x;
	data.posY = map.p_y;  //x and y start position
	convert_orientation(&data, map.player_direction);
	data.planeX = 0, data.planeY = 0.66; //the 2d raycaster version of camera plane

	data.time = 0; //time of current frame
	data.oldTime = 0; //time of previous frame
	i = ((bool)mlx_data_init(&data));
	if (i == false)
		return (1);
	get_textures_from_xpm(&data, map.textures);
	create_image(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}



/* [ cos(a) -sin(a) ]
[ sin(a)  cos(a) ] */
