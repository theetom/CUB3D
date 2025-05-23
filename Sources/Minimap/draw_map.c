/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:35:00 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 13:35:06 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			if (data->world_map[minimap->y][minimap->x] == 1)
				draw_tile(data, minimap, 0xFFFFFF);
			minimap->x += 1;
		}
		minimap->y += 1;
	}
}
