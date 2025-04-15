/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:51:47 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/14 18:15:35 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_math(t_data *data, t_math *math, int x)
{
	math->camera_x = 2 * x / (double)(data->img_w) - 1;
	math->ray_dir_x = data->dirX + data->planeX * math->camera_x;
	math->ray_dir_y = data->dirY + data->planeY * math->camera_x;
	math->map_x = (int)data->posX;
	math->map_y = (int)data->posY;
}

void draw_column(t_math *math, int x)
{
	int h = data->img_h;

	if(side == 0)
	perpWallDist = (sideDistX - deltaDistX);
else
	perpWallDist = (sideDistY - deltaDistY);
int lineHeight = (int)(h / perpWallDist);
//calculate lowest and highest pixel to fill in current stripe
int drawStart = -lineHeight / 2 + h / 2;
if(drawStart < 0)
	drawStart = 0;
int drawEnd = lineHeight / 2 + h / 2;
if(drawEnd >= h)
	drawEnd = h - 1;
t_ColorRGB color = {255, 0, 0};
// Give x and y sides different brightness
if (side == 1)
{
	color = dimColor(color);
}
draw_vertical_line(x, drawStart, drawEnd, color_atoi(color), data);
}

void ray_dda(t_data *data)
{
	bool	hit;

	hit = 0;
	while(hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			// printf("map x%d, mapy%d \n", mapX, mapY);
			if(data->worldMap[mapX][mapY] > 0)
				hit = 1;
		}

}

void	find_ray_angle()
{

}


int create_image(t_data *data)
{
	t_math	math;

	init_math(data, &math, x);
	find_ray_angle();
	ray_dda();
	draw_column();
}