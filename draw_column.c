/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:40:29 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/15 13:04:36 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_column(t_data *data, t_math *math, int x, int h)
{
	t_ColorRGB color;
	int lineHeight;
	int drawStart;
	int drawEnd;
	
	if(math->side == 0)
		math->perpWallDist = (math->sideDistX - math->deltaDistX);
	else
		math->perpWallDist = (math->sideDistY - math->deltaDistY);
	lineHeight = (int)( h/ math->perpWallDist);
	drawStart = -lineHeight / 2 + h / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + h / 2;
	if(drawEnd >= h)
		drawEnd = h - 1;
	color = (t_ColorRGB){255, 0, 0};
	if (math->side == 1)
		color = dimColor(color);
	draw_vertical_line(x, drawStart, drawEnd, color_atoi(color), data);
}
