/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:48:41 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/29 17:02:23 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_vertical_line(int x, int start, int end, int color, t_data *data)
{
	// printf("x: %d, start :%d, end :%d, color %x\n", x, start, end, color);
	int y = start;
	while (y < end && x - 2< data->img_w) // (ver se esse -2 faz sentido --> penso que tenha estado a menos 1)
	{
		// printf("y %d\n", y);
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
	// printf("cheguei\n");
}
