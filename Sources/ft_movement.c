/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:29:01 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/14 10:55:24 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_movement(t_data *data)
{
	if (data->hooks[0] == true) // frente
	{
		if(data->worldMap[(int)data->pos_y][(int)(data->pos_x + data->dirX)] == false)
			data->pos_x += data->dirX * data->moveSpeed;
		if(data->worldMap[(int)(data->pos_y + data->dirY)][(int)(data->pos_x)] == false)
			data->pos_y += data->dirY * data->moveSpeed;
	}
	if (data->hooks[1] == true) // tras
	{
		if(data->worldMap[(int)data->pos_y][(int)(data->pos_x - data->dirX)] == false)
			data->pos_x -= data->dirX * data->moveSpeed;
		if(data->worldMap[(int)(data->pos_y - data->dirY)][(int)(data->pos_x)] == false)
			data->pos_y -= data->dirY * data->moveSpeed;
	}
	if (data->hooks[2] == true) // direita
	{
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
      double oldPlaneX = data->planeX;
      data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
      data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	if (data->hooks[3] == true) // esquerda
	{
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
      double oldPlaneX = data->planeX;
      data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
      data->planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
}
