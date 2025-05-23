/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:58:49 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 12:59:05 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
