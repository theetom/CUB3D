/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 00:42:17 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/16 00:42:38 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_data *data, int end, int *y, int x)
{
	while (*y < end)
	{
		my_mlx_pixel_put(data, x, *y, color_arr_int(data->map->ceiling[0], \
													data->map->ceiling[1], \
													data->map->ceiling[2]));
		(*y)++;
	}
}

void	draw_floor(t_data *data, int end, int *y, int x)
{
	while (*y < end)
	{
		my_mlx_pixel_put(data, x, *y, color_arr_int(data->map->floor[0], \
													data->map->floor[1], \
													data->map->floor[2]));
		(*y)++;
	}
}
