/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:40:29 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 10:17:15 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_wall_size(t_math *math, t_column *column, int h)
{
	if (math->side == 0)
		math->perp_wall_dist = (math->side_dist_x - math->delta_dist_x);
	else
		math->perp_wall_dist = (math->side_dist_y - math->delta_dist_y);
	column->line_h = (int)(h / math->perp_wall_dist);
	column->draw_start = -column->line_h / 2 + h / 2;
	if (column->draw_start < 0)
		column->draw_start = 0;
	column->draw_end = column->line_h / 2 + h / 2;
	if (column->draw_end >= h)
		column->draw_end = h - 1;
}

void	find_texture_values(t_data *data, t_math *math, t_column *column, int h)
{
	column->tex_num = math->wall_dir;
	if (math->side == 0)
		column->wall_x = data->pos_y + math->perp_wall_dist * math->ray_dir_y;
	else
		column->wall_x = data->pos_x + math->perp_wall_dist * math->ray_dir_x;
	column->wall_x -= floor((column->wall_x));
	column->tex_x = (int)(column->wall_x * \
					(double)(data->texture[column->tex_num].t_width));
	if (math->side == 0 && math->ray_dir_x > 0)
		column->tex_x = (data->texture[0].t_width) - column->tex_x - 1;
	if (math->side == 1 && math->ray_dir_y < 0)
		column->tex_x = (data->texture[0].t_width) - column->tex_x - 1;
	column->step = 1.0 * (data->texture[column->tex_num].t_height) \
					/ column->line_h;
	column->tex_pos = (column->draw_start - h / 2 + column->line_h / 2) \
						* column->step;
}

void	draw_wall(t_data *data, t_column *column, int *y, int x)
{
	int	color;
	int	tex_y;

	while (*y <= column->draw_end)
	{
		tex_y = (int)column->tex_pos \
				% (data->texture[column->tex_num].t_height);
		column->tex_pos += column->step;
		color = get_color_from_image(column->tex_x, tex_y, \
									&(data->texture[column->tex_num]));
		my_mlx_pixel_put(data, x, *y, color);
		(*y)++;
	}
}

void	draw_column(t_data *data, t_math *math, int x, int h)
{
	t_column	column;
	int			y;

	find_wall_size(math, &column, h);
	find_texture_values(data, math, &column, h);
	y = 0;
	draw_ceiling(data, column.draw_start, &y, x);
	y = column.draw_start;
	draw_wall(data, &column, &y, x);
	draw_floor(data, data->img_h, &y, x);
}
