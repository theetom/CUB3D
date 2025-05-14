/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ray_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:13:33 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/14 10:54:53 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_ray_angle(t_math *math, t_data *data)
{
	if(math->ray_dir_x < 0)
	{
		math->stepX = -1;
		math->sideDistX = (data->pos_x - math->map_x) * math->deltaDistX;
	}
	else
	{
		math->stepX = 1;
		math->sideDistX = (math->map_x + 1.0 - data->pos_x) * math->deltaDistX;
	}
	if(math->ray_dir_y < 0)
	{
		math->stepY = -1;
		math->sideDistY = (data->pos_y - math->map_y) * math->deltaDistY;
	}
	else
	{
		math->stepY = 1;
		math->sideDistY = (math->map_y + 1.0 - data->pos_y) * math->deltaDistY;
	}
}
