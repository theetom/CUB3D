/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:29:01 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/15 16:54:47 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_movement(t_data *data)
{
	if (data->hooks[0] == true) // frente
	{
		if(data->world_map[(int)data->pos_y][(int)(data->pos_x + data->dir_x)] == false)
			data->pos_x += (data->dir_x * data->moveSpeed) * data->speed;
		if(data->world_map[(int)(data->pos_y + data->dir_y)][(int)(data->pos_x)] == false)
			data->pos_y += (data->dir_y * data->moveSpeed) * data->speed;
	}
	if (data->hooks[1] == true) // tras
	{
		if(data->world_map[(int)data->pos_y][(int)(data->pos_x - data->dir_x)] == false)
			data->pos_x -= (data->dir_x * data->moveSpeed) * data->speed;
		if(data->world_map[(int)(data->pos_y - data->dir_y)][(int)(data->pos_x)] == false)
			data->pos_y -= (data->dir_y * data->moveSpeed * data->speed);
	}
	if (data->hooks[2] == true) // direita
	{
		double oldDirX = data->dir_x;
		data->dir_x = data->dir_x * cos(-data->rotSpeed) - data->dir_y * sin(-data->rotSpeed);
		data->dir_y = oldDirX * sin(-data->rotSpeed) + data->dir_y * cos(-data->rotSpeed);
      double oldPlaneX = data->plane_x;
      data->plane_x = data->plane_x * cos(-data->rotSpeed) - data->plane_y * sin(-data->rotSpeed);
      data->plane_y = oldPlaneX * sin(-data->rotSpeed) + data->plane_y * cos(-data->rotSpeed);
	}
	if (data->hooks[3] == true) // esquerda
	{
		double oldDirX = data->dir_x;
		data->dir_x = data->dir_x * cos(data->rotSpeed) - data->dir_y * sin(data->rotSpeed);
		data->dir_y = oldDirX * sin(data->rotSpeed) + data->dir_y * cos(data->rotSpeed);
      double oldPlaneX = data->plane_x;
      data->plane_x = data->plane_x * cos(data->rotSpeed) - data->plane_y * sin(data->rotSpeed);
      data->plane_y = oldPlaneX * sin(data->rotSpeed) + data->plane_y * cos(data->rotSpeed);
	}
}
