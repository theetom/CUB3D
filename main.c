/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:58:30 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/13 18:16:47 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_data_init(t_data *data)
{
	data->hooks[0] = 0;
	data->hooks[1] = 0;
	data->hooks[2] = 0;
	data->hooks[3] = 0;
	data->debug = 0;
	data->time = 0;
	data->oldTime = 0;
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
	data.posY = map.p_y;
	convert_orientation(&data, map.player_direction);
	i = ((bool)mlx_data_init(&data));
	if (i == false)
		return (1);
	ft_data_init(&data);
	get_textures_from_xpm(&data, map.textures);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}



/* [ cos(a) -sin(a) ]
[ sin(a)  cos(a) ] */
