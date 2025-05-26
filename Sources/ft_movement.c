/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:29:01 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/26 17:42:15 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_movement(t_data *data)
{
	if (data->move > 0)
		ft_move_forward(data);
	if (data->move < 0)
		ft_move_backward(data);
	if (data->rotate < 0)
		ft_rotate_right(data);
	if (data->rotate > 0)
		ft_rotate_left(data);
	if (data->strafe < 0)
		ft_move_left(data);
	if (data->strafe > 0)
		ft_move_right(data);
}

int	ft_movement_verifier(t_data *data)
{
	if (data->move != 0 || data->rotate != 0 || data->strafe != 0)
		return (1);
	else
		return (0);
}
