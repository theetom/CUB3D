/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:59:08 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/22 16:37:45 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_tile(t_data *data, t_minimap *minimap, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < minimap->tile_size)
	{
		x = 0;
		while (x < minimap->tile_size)
		{
			my_mlx_pixel_put(data, \
				minimap->x * minimap->tile_size + x + minimap->pos_x, \
				minimap->y * minimap->tile_size + y + minimap->pos_y, color);
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data, t_minimap *minimap)
{
	minimap->y = 0;
	while (minimap->y < data->map->max_y)
	{
		minimap->x = 0;
		while (minimap->x < data->map->max_x)
		{
			if (data->world_map[minimap->y][minimap->x] == 0)
				draw_tile(data, minimap, minimap->color);
			minimap->x += 1;
		}
		minimap->y += 1;
	}
}

void	draw_frame(t_data *data, t_minimap *minimap)
{
	minimap->y = 0;
	while (minimap->y < data->map->max_y)
	{
		minimap->x = 0;
		while (minimap->x < data->map->max_x)
		{
			draw_tile(data, minimap, 0xFFFFFF);
			minimap->x += 1;
		}
		minimap->y += 1;
	}
}

void	draw_player(t_data *data, t_minimap *minimap)
{
	int	px;
	int	py;
	int	x;
	int	y;

	px = minimap->pos_x + (int)(data->pos_x * minimap->tile_size) - 2;
	py = minimap->pos_y + (int)(data->pos_y * minimap->tile_size) - 2;
	y = 0;
	while (y <= minimap->player_size)
	{
		x = 0;
		while (x <= minimap->player_size)
		{
			my_mlx_pixel_put(data, px + x, py + y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	t_minimap	minimap;

	ft_bzero(&minimap, sizeof minimap);
	minimap.color = 0x222222;
	minimap.tile_size = 10;
	minimap.player_size = 5;
	minimap.pos_x = 20;
	minimap.pos_y = 20;
	draw_frame(data, &minimap);
	draw_map(data, &minimap);
	draw_player(data, &minimap);
}
