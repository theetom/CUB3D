/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:49:34 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/12 22:44:33 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_fps(t_data *data)
{
	double	frame_time;
	char	fps_text[50];
	char	speed_text[100];
	char	ptr[100];

	data->time = getTicks();
	frame_time = (data->time - data->oldTime) / 1000.0;
	data->oldTime = data->time;
	if (frame_time > 0)
		sprintf(fps_text, "FPS: %d", (int)(1.0 / frame_time));
	else
		sprintf(fps_text, "FPS: --");
	data->moveSpeed = frame_time * 5.0;
	data->rotSpeed = frame_time * 3.0;
	mlx_string_put(data->mlx, data->mlx_win, 10, 20, 0x00FFFFFF, fps_text);
	mlx_string_put(data->mlx, data->mlx_win, 10, 40, 0x00FFFFFF, speed_text);
	sprintf(ptr, "dir x : %f dir y : %f", data->dirX, data->dirY);
	mlx_string_put(data->mlx, data->mlx_win, 10, 60, 0x00FFFFFF, ptr);
}

/* while (1 / frameTime > 30)
{
	data->time = getTicks();
	frameTime = (data->time - data->oldTime) / 1000.0;
} */