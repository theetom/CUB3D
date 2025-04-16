/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:51:47 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/15 12:13:25 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ray_dda(t_math *math, t_data *data)
{
	bool	hit;

	hit = 0;
	while(hit == 0)
		{
			if(math->sideDistX < math->sideDistY)
			{
				math->sideDistX += math->deltaDistX;
				math->map_x += math->stepX;
				math->side = 0;
			}
			else
			{
				math->sideDistY += math->deltaDistY;
				math->map_y += math->stepY;
				math->side = 1;
			}
			//Check if ray has hit a wall
			// printf("map x%d, mapy%d \n", mapX, mapY);
			if(data->worldMap[math->map_x][math->map_y] > 0)
				hit = 1;
		}

}
