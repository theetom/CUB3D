/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:58:30 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 09:59:50 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	mlx_data_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return (0);
	mlx_get_screen_size(data->mlx, &data->img_w, &data->img_h);
	data->img_w /= 2;
	data->img_h /= 2;
	data->mlx_win = \
			mlx_new_window(data->mlx, data->img_w, data->img_h, "Our Cub3D");
	if (data->mlx_win == NULL)
		return (0);
	ft_hooks(data);
	mlx_do_key_autorepeatoff(data->mlx);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
									&data->line_length, &data->endian);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_map		map;
	t_minimap	minimap;

	ft_bzero(&data, sizeof data);
	data.map = &map;
	data.minimap = &minimap;
	if (parsing_map(argc, argv, &map) == 1)
		return (1);
	ft_data_init(&data);
	convert_orientation(&data, map.player_direction);
	if (mlx_data_init(&data) == 0)
	{
		printf("mlx init error\n");
		delete_everything(&data);
	}
	if (get_textures_from_xpm(&data, map.textures) == 0)
	{
		printf("texture error\n");
		delete_everything(&data);
	}
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
