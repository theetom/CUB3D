/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:45:02 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/22 15:58:07 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_movement_hooks_on_release(int k, t_data *data)
{
	if (k == 97 || k == 100)
		data->strafe = 0;
	if (k == 119 || k == 115)
		data->move = 0;
	if (data->mouse != 1 && (k == 65361 || k == 65363))
		data->rotate = 0;
	return (0);
}

int	ft_keyrelease(int k, t_data *data)
{
	ft_movement_hooks_on_release(k, data);
	if (k == 65505)
		data->speed = 1;
	if (k == 32)
	{
		if (data->debug == 0)
			data->debug = 1;
		else
			data->debug = 0;
	}
	if (k == 65288)
	{
		if (data->mouse == 0)
			data->mouse = 1;
		else
			data->mouse = 0;
	}
	return (0);
}

int	ft_keypress(int k, t_data *data)
{
	if (k == 65307)
		delete_everything(data);
	if (k == 119)
		data->move = 1;
	if (k == 115)
		data->move = -1;
	if (k == 97)
		data->strafe = -1;
	if (k == 100)
		data->strafe = 1;
	if (data->mouse != 1 && k == 65361)
		data->rotate = -1;
	if (data->mouse != 1 && k == 65363)
		data->rotate = 1;
	if (k == 65505)
		data->speed = 3;
	return (0);
}

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

void	ft_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 06, 1l << 6, ft_mouse, data);
	mlx_hook(data->mlx_win, 02, (1L << 0), ft_keypress, data);
	mlx_hook(data->mlx_win, 03, (1L << 1), ft_keyrelease, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, delete_everything, data);
}
