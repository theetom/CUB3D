/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:39:35 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/16 00:56:11 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_math(t_data *data, t_math *math, int x)
{
	math->camera_x = 2 * x / (double)(data->img_w) - 1;
	math->ray_dir_x = data->dir_x + data->plane_x * math->camera_x;
	math->ray_dir_y = data->dir_y + data->plane_y * math->camera_x;
	math->map_x = (int)data->pos_x;
	math->map_y = (int)data->pos_y;
	if (math->ray_dir_x == 0)
		math->delta_dist_x = 1e30;
	else
		math->delta_dist_x = fabs(1.0 / math->ray_dir_x);
	if (math->ray_dir_y == 0)
		math->delta_dist_y = 1e30;
	else
		math->delta_dist_y = fabs(1.0 / math->ray_dir_y);
	math->hit = 0;
}
