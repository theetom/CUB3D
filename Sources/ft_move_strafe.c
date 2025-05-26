/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_strafe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:00:12 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/26 14:51:11 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_left(t_data *data)
{
	double	strafe_x;
	double	strafe_y;

	strafe_x = -data->plane_x;
	strafe_y = -data->plane_y;
	if (0 < (data->pos_x + strafe_x * data->move_speed * data->speed) \
	&& data->map->max_x > (data->pos_x + strafe_x \
	* data->move_speed * data->speed))
	{
		if (data->world_map[(int)(data->pos_y)] \
		[(int)(data->pos_x + strafe_x * data->move_speed * data->speed)] \
		== 0)
			data->pos_x += strafe_x * data->move_speed * data->speed;
	}
	if (0 < (data->pos_y + strafe_y * data->move_speed * data->speed) \
	&& data->map->max_y > (data->pos_y + strafe_y \
	* data->move_speed * data->speed))
	{
		if (data->world_map \
		[(int)(data->pos_y + strafe_y * data->move_speed * data->speed)] \
		[(int)(data->pos_x)] == 0)
			data->pos_y += strafe_y * data->move_speed * data->speed;
	}
}

void	ft_move_right(t_data *data)
{
	double	strafe_x;
	double	strafe_y;

	strafe_x = data->plane_x;
	strafe_y = data->plane_y;
	if (0 < (data->pos_x + strafe_x * data->move_speed * data->speed) \
	&& data->map->max_x > (data->pos_x + strafe_x \
	* data->move_speed * data->speed))
	{
		if (data->world_map[(int)(data->pos_y)]
		[(int)(data->pos_x + strafe_x * data->move_speed * data->speed)] == 0)
			data->pos_x += strafe_x * data->move_speed * data->speed;
	}
	if (0 < (data->pos_y + strafe_y * data->move_speed * data->speed) \
	&& data->map->max_y > (data->pos_y + strafe_y \
	* data->move_speed * data->speed))
	{
		if (data->world_map \
		[(int)(data->pos_y + strafe_y * data->move_speed * data->speed)] \
		[(int)(data->pos_x)] == 0)
			data->pos_y += strafe_y * data->move_speed * data->speed;
	}
}
