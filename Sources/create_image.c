/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:55:03 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/16 01:17:20 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_walls(t_data *data, int h)
{
	t_math	math;
	int		x;

	x = 0;
	while (x < data->img_w)
	{
		init_math(data, &math, x);
		find_ray_angle(&math, data);
		ray_dda(&math, data);
		draw_column(data, &math, x, h);
		x++;
	}
}

int	create_image(t_data *data)
{
	int	h;

	h = (data->img_h);
	render_walls(data, h);
	return (0);
}
