/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:59:40 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/22 16:11:25 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate_left(t_data *data)
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

void	ft_rotate_right(t_data *data)
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
