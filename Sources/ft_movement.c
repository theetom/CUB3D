/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:29:01 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/16 18:08:37 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_move_forward(t_data *data)
{
	int max_x;
	int max_y;

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

static void	ft_move_backward(t_data *data)
{
	int max_x;
	int max_y;

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

static void	ft_move_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(-data->rot_speed) \
					- data->dir_y * sin(-data->rot_speed);
	data->dir_y = old_dir_x * sin(-data->rot_speed) \
					+ data->dir_y * cos(-data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(-data->rot_speed) \
					- data->plane_y * sin(-data->rot_speed);
	data->plane_y = old_plane_x * sin(-data->rot_speed) \
					+ data->plane_y * cos(-data->rot_speed);
}

static void	ft_move_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->dir_x;
	data->dir_x = data->dir_x * cos(data->rot_speed) \
					- data->dir_y * sin(data->rot_speed);
	data->dir_y = old_dir_x * sin(data->rot_speed) \
					+ data->dir_y * cos(data->rot_speed);
	old_plane_x = data->plane_x;
	data->plane_x = data->plane_x * cos(data->rot_speed) \
					- data->plane_y * sin(data->rot_speed);
	data->plane_y = old_plane_x * sin(data->rot_speed) \
					+ data->plane_y * cos(data->rot_speed);
}

void	ft_movement(t_data *data)
{
	if (data->hooks[0] == true)
		ft_move_forward(data);
	if (data->hooks[1] == true)
		ft_move_backward(data);
	if (data->hooks[2] == true)
		ft_move_right(data);
	if (data->hooks[3] == true)
		ft_move_left(data);
}
