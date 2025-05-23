/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:36:17 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 13:36:35 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_player(t_data *data, t_minimap *minimap)
{
	int	px;
	int	py;
	int	x;
	int	y;

	px = minimap->pos_x + (int)(data->pos_x * minimap->tile_size);
	py = minimap->pos_y + (int)(data->pos_y * minimap->tile_size);
	y = -minimap->player_size;
	while (y <= minimap->player_size)
	{
		x = -minimap->player_size;
		while (x <= minimap->player_size)
		{
			my_mlx_pixel_put(data, px + x, py + y, 0xFF0000);
			x++;
		}
		y++;
	}
}
