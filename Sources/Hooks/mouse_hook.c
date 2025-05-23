/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:55:30 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 12:56:55 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_mouse(int x, int y, t_data *data)
{
	int	base;

	(void)y;
	if (data->mouse == 1)
	{
		mlx_mouse_move(data->mlx, data->mlx_win, \
					data->img_w / 2, data->img_h / 2);
		base = data->img_w / 2;
		if (base == x)
		{
			data->rotate = 0;
		}
		else if (base > x)
			data->rotate = -1;
		else
			data->rotate = 1;
	}
	return (0);
}
