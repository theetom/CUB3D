/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:49:34 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/15 23:50:29 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_fps(t_data *data) /* put after put iamge to window because of mlx string put */
{
	double	frameTime;
	char	fps_text[50];
	char	speed_text[100];
	char	ptr[100];

	data->time = getTicks();

	printf("x : %f y : %f\n", data->posX, data->posY);

	frameTime = (data->time - data->oldTime) / 1000.0;
    data->oldTime = data->time;

	if (frameTime > 0) {
        sprintf(fps_text, "FPS: %.2f", 1.0 / frameTime);
    } else {
        sprintf(fps_text, "FPS: --");
    }


	data->moveSpeed = frameTime * 5.0;
    data->rotSpeed = frameTime * 3.0;
    sprintf(speed_text, "Move Speed: %.5f, Rot Speed: %.5f", data->moveSpeed, data->rotSpeed);
	mlx_string_put(data->mlx, data->mlx_win, 10, 20, 0x00FFFFFF, fps_text);
    mlx_string_put(data->mlx, data->mlx_win, 10, 40, 0x00FFFFFF, speed_text);
	sprintf(ptr, "dir x : %f dir y : %f", data->dirX, data->dirY);
	mlx_string_put(data->mlx, data->mlx_win, 10, 60, 0x00FFFFFF, ptr);
	while (1 / frameTime > 20)
	{
		data->time = getTicks();
		frameTime = (data->time - data->oldTime) / 1000.0;
		usleep(10);
	}
}