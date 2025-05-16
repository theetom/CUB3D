/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ray_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:13:33 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/16 00:57:12 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_ray_angle(t_math *math, t_data *data)
{
	if (math->ray_dir_x < 0)
	{
		math->step_x = -1;
		math->side_dist_x = \
					(data->pos_x - math->map_x) * math->delta_dist_x;
	}
	else
	{
		math->step_x = 1;
		math->side_dist_x = \
					(math->map_x + 1.0 - data->pos_x) * math->delta_dist_x;
	}
	if (math->ray_dir_y < 0)
	{
		math->step_y = -1;
		math->side_dist_y = \
					(data->pos_y - math->map_y) * math->delta_dist_y;
	}
	else
	{
		math->step_y = 1;
		math->side_dist_y = \
					(math->map_y + 1.0 - data->pos_y) * math->delta_dist_y;
	}
}
