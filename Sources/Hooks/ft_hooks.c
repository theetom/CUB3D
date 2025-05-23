/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:45:02 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 12:58:48 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_keyrelease(int k, t_data *data)
{
	ft_movement_hooks_on_release(k, data);
	ft_minimap_hooks(k, data->minimap);
	if (k == 65505)
		data->speed = 1;
	if (k == 32)
		data->debug ^= 1;
	if (k == 65288)
		data->mouse ^= 1;
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

void	ft_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 06, 1l << 6, ft_mouse, data);
	mlx_hook(data->mlx_win, 02, (1L << 0), ft_keypress, data);
	mlx_hook(data->mlx_win, 03, (1L << 1), ft_keyrelease, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, delete_everything, data);
}
