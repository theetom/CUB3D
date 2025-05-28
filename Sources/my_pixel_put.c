/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:17:57 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/28 15:40:06 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->img_w || y < 0 || y >= data->img_h)
		return ;
	dst = data->addr
		+ (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color_from_image(int x, int y, t_texture *texture)
{
	char	*dst;

	dst = texture->addr
		+ (y * texture->size_line + x * (texture->bit_p_pixel / 8));
	return (*(unsigned int *)dst);
}
