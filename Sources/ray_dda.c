/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_dda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:51:47 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/15 16:54:47 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_side(t_math *math)
{
	int	wall_dir;

	if (math->side == 0)
	{
		if (math->step_x > 0)
			wall_dir = EAST;
		else
			wall_dir = WEST;
	}
	else
	{
		if (math->step_y > 0)
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
		if (math->side_dist_x < math->side_dist_y)
		{
			math->side_dist_x += math->delta_dist_x;
			math->map_x += math->step_x;
			math->side = 0;
		}
		else
		{
			math->side_dist_y += math->delta_dist_y;
			math->map_y += math->step_y;
			math->side = 1;
		}
		if ((math->map_x >= 0 && math->map_y >= 0))
		{
			if (data->world_map[math->map_y][math->map_x] > 0)
				hit = 1;
			math->wall_dir = get_side(math);
		}
	}
}
