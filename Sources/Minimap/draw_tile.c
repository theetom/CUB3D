/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:34:24 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 13:35:25 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
