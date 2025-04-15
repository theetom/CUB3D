/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:55:03 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/14 18:04:22 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// Define color constants
const t_ColorRGB RGB_Red    = {255, 0, 0};
const t_ColorRGB RGB_Green  = {0, 255, 0};
const t_ColorRGB RGB_Blue   = {0, 0, 255};
const t_ColorRGB RGB_White  = {255, 255, 255};
const t_ColorRGB RGB_Yellow = {255, 255, 0};

void	render_walls(t_data *data)
{
	t_math	wall;
	int	x;
	int w = data->img_w;
	int h = data->img_h;

	x = 0;
	while (x <= data->img_w)
	{
		double cameraX = 2 * x / (double)(data->img_w) - 1; //x-coordinate in camera space
		double rayDirX = data->dirX + data->planeX * cameraX;
		double rayDirY = data->dirY + data->planeY * cameraX;
		int mapX = (int)data->posX;
		int mapY = (int)data->posY;
		double sideDistX;
		double sideDistY;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1.0 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1.0 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
  
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
		}





		x++;
	}
}

int create_image(t_data *data)
{
	render_walls(data);
 

	
	return 0;
}

