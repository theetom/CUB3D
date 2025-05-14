/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:40:29 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/14 11:07:06 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_data *data, int end, int *y, int x, int color)
{
	while (*y < end)
	{
		my_mlx_pixel_put(data, x, *y, color);
		(*y)++;
	}
}

void draw_column(t_data *data, t_math *math, int x, int h)
{
	int lineHeight;
	int drawStart;
	int drawEnd;
	
	if(math->side == 0)
		math->perpWallDist = (math->sideDistX - math->deltaDistX);
	else
		math->perpWallDist = (math->sideDistY - math->deltaDistY);
	lineHeight = (int)( h / math->perpWallDist); // * 0.75;
	drawStart = -lineHeight / 2 + h / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + h / 2;
	if(drawEnd >= h)
		drawEnd = h - 1;


	// TEXTURE

	int texNum = math->wall_dir; // replace 0 math->wall_dir

	double wallX;
	if (math->side == 0)
		wallX = data->pos_y + math->perpWallDist * math->ray_dir_y;
	else
		wallX = data->pos_x + math->perpWallDist * math->ray_dir_x;
	wallX -= floor((wallX));

	int texX = (int)(wallX * (double)(data->texture[texNum].t_width));
	if(math->side == 0 && math->ray_dir_x > 0)
		texX = (data->texture[0].t_width) - texX - 1;
	if(math->side == 1 && math->ray_dir_y < 0)
		texX = (data->texture[0].t_width) - texX - 1;


	double step = 1.0 * (data->texture[texNum].t_height) / lineHeight;
	double texPos = (drawStart - h / 2 + lineHeight / 2) * step;

	int y = 0;
	draw_ceiling(data, drawStart, &y, x, \
						color_arr_int(data->map->floor[0],\
							data->map->floor[1],\
							data->map->floor[2]));
	y = drawStart;
	while(y <= drawEnd)
    {
		int texY = (int)texPos & (data->texture[texNum].t_height - 1);
        texPos += step;
        int color = get_color_from_image(texX, texY, &(data->texture[texNum]));
		my_mlx_pixel_put(data, x, y, color);
		y++;
    }
	draw_ceiling(data, data->img_h, &y, x, color_arr_int(data->map->ceiling[0],\
							data->map->ceiling[1],\
							data->map->ceiling[2]));

	// color = get_color(math);
/* 	if (math->side == 1)
		color = dimColor(color); */
	// printf("x;%d start;%d end;%d color;%d\n",x, drawStart, drawEnd, color_atoi(color));
	// draw_vertical_line(x, drawStart, drawEnd, color_atoi(color), data);
}
