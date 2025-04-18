/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:55:03 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/18 02:01:29 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// Define color constants
const t_ColorRGB RGB_Red    = {255, 0, 0};
const t_ColorRGB RGB_Green  = {0, 255, 0};
const t_ColorRGB RGB_Blue   = {0, 0, 255};
const t_ColorRGB RGB_White  = {255, 255, 255};
const t_ColorRGB RGB_Yellow = {255, 255, 0};

void	render_floor(t_math *math, t_data *data, int h)
{
	int	y;

	y = 0;
	(void)math;
	t_ColorRGB color = RGB_Green;
	t_ColorRGB color2 = RGB_Blue; 
	while (y < h)
	{
		float rayDirX0 = data->dirX - data->planeX;
		float rayDirY0 = data->dirY - data->planeY;
		float rayDirX1 = data->dirX + data->planeX;
		float rayDirY1 = data->dirY + data->planeY;
		int p = y - data->img_h / 2;
		float posZ = 0.5 * data->img_h;
		float rowDistance = posZ / p;
		float floorStepX = rowDistance * (rayDirX1 - rayDirX0) / data->img_w;
		float floorStepY = rowDistance * (rayDirY1 - rayDirY0) / data->img_w;
		float floorX = data->posX + rowDistance * rayDirX0;
		float floorY = data->posY + rowDistance * rayDirY0;

		int x = 0;

		while (++x < data->img_w)
		{
			// int cellX = (int)(floorX);
			// int cellY = (int)(floorY);
			// int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
			// int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			my_mlx_pixel_put(data, x, data->img_h - y - 1, color_atoi(color2)); // floor
			my_mlx_pixel_put(data, x, y, color_atoi(color)); // ceiling
		}
		y++;
	}
}

void	render_walls(t_math *math, t_data *data, int h)
{

	int	x;

	x = 0;
	while (++x < data->img_w)
	{
		init_math(data, math, x);
		find_ray_angle(math, data);
		ray_dda(math, data);
		draw_column(data, math, x, h);
	}
}

int create_image(t_data *data)
{
	t_math	math;
	int h = data->img_h;

	render_floor(&math, data, h);
	render_walls(&math, data, h);
 
	return (0);
}
