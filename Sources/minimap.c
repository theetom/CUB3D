/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:59:08 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/22 00:43:49 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_minimap
{
	int pos_x;
	int pos_y;
	int x;
	int y;
	int color;
	int tile_size;
}	t_minimap;

void draw_tile(t_data *data, t_minimap *minimap, int color)
{
	int x;
	int y;

	y = 0;
	while (y < minimap->tile_size)
	{
		x = 0;
		while (x < minimap->tile_size)
		{
			my_mlx_pixel_put(data, minimap->x * minimap->tile_size + x + minimap->pos_x,
				minimap->y * minimap->tile_size + y + minimap->pos_y, color);
			x++;
		}
		y++;
	}
}

void draw_map(t_data *data, t_minimap *minimap)
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

void draw_frame(t_data *data, t_minimap *minimap)
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

// void draw_player(void)
// {
// 	// Implement the function to draw the player
// }

void draw_minimap(t_data *data)
{
	t_minimap minimap;
	
	ft_bzero(&minimap, sizeof minimap);
	minimap.color = 0x222222;
	minimap.tile_size = 10;
	minimap.pos_x = 20;
	minimap.pos_y = 20;

	draw_frame(data, &minimap);
	draw_map(data, &minimap);
	// draw_player(data);
}