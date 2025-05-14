/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:25:08 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/13 17:47:11 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_east(t_data *data)
{
	data->dirX = 1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
}

static void	ft_west(t_data *data)
{
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = -0.66;
}

static void	ft_north(t_data *data)
{
	data->dirX = 0;
	data->dirY = -1;
	data->planeX = 0.66;
	data->planeY = 0;
}

static void	ft_south(t_data *data)
{
	data->dirX = 0;
	data->dirY = 1;
	data->planeX = -0.66;
	data->planeY = 0;
}


void convert_orientation(t_data *data, char pos)
{
	if (pos == 'N')
		ft_north(data);
	if (pos == 'S')
		ft_south(data);
	if (pos == 'W')
		ft_west(data);
	if (pos == 'E')
		ft_east(data);
}
