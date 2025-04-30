/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:40:29 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/30 16:00:58 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ColorRGB	get_color(t_math *math)
{
	if (math->wall_dir == 0)
		return ((t_ColorRGB){255, 0, 0});
	if (math->wall_dir == 1)
		return ((t_ColorRGB){255, 0, 255});
	if (math->wall_dir == 2)
		return ((t_ColorRGB){255, 255, 255});
	if (math->wall_dir == 3)
		return ((t_ColorRGB){255, 255, 0});
}

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
	lineHeight = (int)( h / math->perpWallDist) * 0.75;
	drawStart = -lineHeight / 2 + h / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + h / 2;
	if(drawEnd >= h)
		drawEnd = h - 1;
	color = get_color(math);
/* 	if (math->side == 1)
		color = dimColor(color); */
	// printf("x;%d start;%d end;%d color;%d\n",x, drawStart, drawEnd, color_atoi(color));
	draw_vertical_line(x, drawStart, drawEnd, color_atoi(color), data);
}
