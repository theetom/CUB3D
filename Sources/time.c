/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 23:49:34 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/16 00:46:41 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_fps(t_data *data)
{
	double	frame_time;
	char	*fps_text;
	char	*fps;

	data->time = get_ticks();
	frame_time = (data->time - data->old_time) / 1000.0;
	data->old_time = data->time;
	data->move_speed = frame_time * 5.0;
	data->rot_speed = frame_time * 3.0;
	if (data->debug == 1)
	{
		if (frame_time > 0)
		{
			fps = ft_itoa((int)(1.0 / frame_time));
			fps_text = ft_strjoin("FPS : ", fps);
			free(fps);
		}
		else
			fps_text = ft_strdup("FPS: --");
		mlx_string_put(data->mlx, data->mlx_win, 10, 20, 0x00FFFFFF, fps_text);
		free(fps_text);
	}
}

/* while (1 / frameTime > 30)
{
	data->time = getTicks();
	frameTime = (data->time - data->oldTime) / 1000.0;
} */