/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:55:03 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/15 16:53:48 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// Define color constants
const t_ColorRGB RGB_Red    = {255, 0, 0};
const t_ColorRGB RGB_Green  = {0, 255, 0};
const t_ColorRGB RGB_Blue   = {0, 0, 255};
const t_ColorRGB RGB_White  = {255, 255, 255};
const t_ColorRGB RGB_Yellow = {255, 255, 0};

/* typedef struct s_floor
{
	float rayDirX0;
	float rayDirY0;
	float rayDirX1;
	float rayDirY1;
	int p;
	float posZ;
	float rowDistance;
	float floorStepX;
	float floorStepY;
	float floorX;
	float floorY;
} t_floor;
 */
/* void	render_floor(t_data *data, int h)
{
	t_floor floor;
	int	y;

	y = 0;
	t_ColorRGB color = RGB_Green;
	t_ColorRGB color2 = RGB_Blue;

	while (y < h)
	{
		floor.rayDirX0 = data->dirX - data->plane_x;
		floor.rayDirY0 = data->dir_y - data->planeY;
		floor.rayDirX1 = data->dirX + data->plane_x;
		floor.rayDirY1 = data->dir_y + data->planeY;
		floor.p = y - data->img_h / 2;
		floor.posZ = 0.5 * data->img_h;
		floor.rowDistance = floor.posZ / floor.p;
		floor.floorStepX = floor.rowDistance * (floor.rayDirX1 - floor.rayDirX0) / data->img_w;
		floor.floorStepY = floor.rowDistance * (floor.rayDirY1 - floor.rayDirY0) / data->img_w;
		floor.floorX = data->posX + floor.rowDistance * floor.rayDirX0;
		floor.floorY = data->posY + floor.rowDistance * floor.rayDirY0;

		int x = 0;

		while (x < data->img_w)
		{
			// int cellX = (int)(floorX);
			// int cellY = (int)(floorY);
			// int tx = (int)(texWidth * (floorX - cellX)) & (texWidth - 1);
			// int ty = (int)(texHeight * (floorY - cellY)) & (texHeight - 1);

			floor.floorX += floor.floorStepX;
			floor.floorY += floor.floorStepY;

			my_mlx_pixel_put(data, x, h - y - 1, color_atoi(color2)); // floor
			my_mlx_pixel_put(data, x, y, color_atoi(color)); // ceiling
			x++;
		}
		y++;
	}
} */

void	render_walls(t_data *data, int h)
{
	t_math math;
	int	x;

	x = 0;
	while (x < data->img_w)
	{
		init_math(data, &math, x);
		find_ray_angle(&math, data);
		ray_dda(&math, data);
		draw_column(data, &math, x, h);
		x++;
	}
}

int create_image(t_data *data)
{
	int h = (data->img_h);

	// render_floor(data, h);
	render_walls(data, h);
 
	return (0);
}
