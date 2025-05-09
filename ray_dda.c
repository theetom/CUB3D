/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:51:47 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/09 16:27:24 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_side(t_math *math)
{
	int	wall_dir;

	if (math->side == 0) // vertical wall
	{
		if (math->stepX > 0)
			wall_dir = EAST; 
		else
			wall_dir = WEST;
	}
	else // horizontal wall
	{
		if (math->stepY > 0)
			wall_dir = SOUTH;
		else
			wall_dir = NORTH;
	}
	return (wall_dir);
}

void ray_dda(t_math *math, t_data *data)
{
	bool	hit;

	hit = 0;
	while(hit == 0 && (math->map_x >= 0 && math->map_y >= 0)) // ver se essa condicao (desnessaria)
	{
		if(math->sideDistX < math->sideDistY) // vai dar orientacao parede mudar depois
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
		if ((math->map_x >= 0 && math->map_y >= 0)) // ver se essa condicao (desnessaria)
		{
			// printf("%d %d\n", math->map_x, math->map_y);
			// printf("%d\n", data->worldMap[math->map_y][math->map_x]);
			if(data->worldMap[math->map_y][math->map_x] > 0)
			{
				hit = 1;
			}
			math->wall_dir = get_side(math);
		}
	}
}
