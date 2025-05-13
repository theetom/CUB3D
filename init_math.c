/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:39:35 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/13 16:27:44 by toferrei         ###   ########.fr       */
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
	if (math->ray_dir_x == 0)
		math->deltaDistX = 1e30;
	else
		math->deltaDistX = fabs(1.0 / math->ray_dir_x);
	if (math->ray_dir_y == 0)
		math->deltaDistY = 1e30;
	else
		math->deltaDistY = fabs(1.0 / math->ray_dir_y);
	// math->deltaDistX = (math->ray_dir_x == 0) ? 1e30 : fabs(1.0 / math->ray_dir_x);
	// math->deltaDistY = (math->ray_dir_y == 0) ? 1e30 : fabs(1.0 / math->ray_dir_y);
	math->hit = 0;
}
