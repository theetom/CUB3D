/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ray_angle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 12:13:33 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/15 12:14:09 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_ray_angle(t_math *math, t_data *data)
{
	if(math->ray_dir_x < 0)
	{
		math->stepX = -1;
		math->sideDistX = (data->posX - math->map_x) * math->deltaDistX;
	}
	else
	{
		math->stepX = 1;
		math->sideDistX = (math->map_x + 1.0 - data->posX) * math->deltaDistX;
	}
	if(math->ray_dir_y < 0)
	{
		math->stepY = -1;
		math->sideDistY = (data->posY - math->map_y) * math->deltaDistY;
	}
	else
	{
		math->stepY = 1;
		math->sideDistY = (math->map_y + 1.0 - data->posY) * math->deltaDistY;
	}
}
