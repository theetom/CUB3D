/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:51:47 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/12 22:46:30 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_side(t_math *math)
{
	int	wall_dir;

	if (math->side == 0)
	{
		if (math->stepX > 0)
			wall_dir = EAST;
		else
			wall_dir = WEST;
	}
	else
	{
		if (math->stepY > 0)
			wall_dir = SOUTH;
		else
			wall_dir = NORTH;
	}
	return (wall_dir);
}

void	ray_dda(t_math *math, t_data *data)
{
	bool	hit;

	hit = 0;
	while (hit == 0 && (math->map_x >= 0 && math->map_y >= 0))
	{
		if (math->sideDistX < math->sideDistY)
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
		if ((math->map_x >= 0 && math->map_y >= 0))
		{
			if (data->worldMap[math->map_y][math->map_x] > 0)
				hit = 1;
			math->wall_dir = get_side(math);
		}
	}
}
