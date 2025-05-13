/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:25:29 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/13 18:06:02 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	has_movement(int *mov)
{
	int	n;

	n = 0;
	while (n <= 3)
	{
		if (mov[n] == 1)
			return (1);
		n++;
	}
	return (0);
}

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	if (has_movement(data->hooks) == 1)
		ft_movement(data);
	create_image(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	display_fps(data);
	return (0);
}
