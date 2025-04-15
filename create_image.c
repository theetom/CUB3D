/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:55:03 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/15 12:38:52 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

// Define color constants
const t_ColorRGB RGB_Red    = {255, 0, 0};
const t_ColorRGB RGB_Green  = {0, 255, 0};
const t_ColorRGB RGB_Blue   = {0, 0, 255};
const t_ColorRGB RGB_White  = {255, 255, 255};
const t_ColorRGB RGB_Yellow = {255, 255, 0};

void	render_walls(t_data *data)
{
	t_math	wall;
	int	x;
	int h = data->img_h;

	x = 0;
	while (x <= data->img_w)
	{
		init_math(data, &wall, x);
		find_ray_angle(&wall, data);
		ray_dda(&wall, data);
		draw_column(data, &wall, x, h);
		x++;
	}
}

int create_image(t_data *data)
{
	render_walls(data);
 

	
	return 0;
}

