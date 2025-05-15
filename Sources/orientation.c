/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 17:25:08 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/15 16:54:25 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_east(t_data *data)
{
	data->dir_x = 1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
}

static void	ft_west(t_data *data)
{
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = -0.66;
}

static void	ft_north(t_data *data)
{
	data->dir_x = 0;
	data->dir_y = -1;
	data->plane_x = 0.66;
	data->plane_y = 0;
}

static void	ft_south(t_data *data)
{
	data->dir_x = 0;
	data->dir_y = 1;
	data->plane_x = -0.66;
	data->plane_y = 0;
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
