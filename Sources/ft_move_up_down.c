/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_up_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:00:16 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/22 16:18:39 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_forward(t_data *data)
{
	int	max_x;
	int	max_y;

	max_x = data->map->max_x;
	max_y = data->map->max_y;
	if (0 < (data->pos_x + data->dir_x) \
	&& max_x > (data->pos_x + data->dir_x))
	{
		if (data->world_map[(int)data->pos_y] \
		[(int)(data->pos_x + data->dir_x)] == 0)
			data->pos_x += (data->dir_x * data->move_speed) * data->speed;
	}
	if (0 < (data->pos_y + data->dir_y) \
		&& max_y > (data->pos_y + data->dir_y))
	{
		if (data->world_map[(int)(data->pos_y + data->dir_y)] \
		[(int)(data->pos_x)] == 0)
			data->pos_y += (data->dir_y * data->move_speed) * data->speed;
	}
}

void	ft_move_backward(t_data *data)
{
	int	max_x;
	int	max_y;

	max_x = data->map->max_x;
	max_y = data->map->max_y;
	if (0 < (data->pos_x + data->dir_x) \
	&& max_x > (data->pos_x + data->dir_x))
	{
		if (data->world_map[(int)data->pos_y] \
		[(int)(data->pos_x - data->dir_x)] == 0)
			data->pos_x -= (data->dir_x * data->move_speed) * data->speed;
	}
	if (0 < (data->pos_y + data->dir_y) \
	&& max_y > (data->pos_y + data->dir_y))
	{
		if (data->world_map[(int)(data->pos_y - data->dir_y)] \
		[(int)(data->pos_x)] == 0)
			data->pos_y -= (data->dir_y * data->move_speed * data->speed);
	}
}
