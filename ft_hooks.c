/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:45:02 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/12 15:16:33 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_keyrelease(int k, t_data *data)
{
	if (k == 119)
		data->hooks[0] = false;
	if (k == 115)
		data->hooks[1] = false;
	if (k == 100)
		data->hooks[2] = false;
	if (k == 97)
		data->hooks[3] = false;
}

int	ft_keypress(int k, t_data *data)
{
	if (k == 0xff1b)
		delete_everything(data);
	if (k == 119)
		data->hooks[0] = true;
	if (k == 115)
		data->hooks[1] = true;
	if (k == 100)
		data->hooks[2] = true;
	if (k == 97)
		data->hooks[3] = true;
	return 0;
}

void	ft_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 02, (1L << 0), ft_keypress, data);
	mlx_hook(data->mlx_win, 03, (1L << 1), ft_keyrelease, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, delete_everything, data);
}
