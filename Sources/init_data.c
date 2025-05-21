/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:30:22 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/21 22:49:32 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_data_init(t_data *data, t_map *map)
{
	data->world_map = map->int_map;
	data->pos_x = map->p_x;
	data->pos_y = map->p_y;
	data->debug = 0;
	data->time = 0;
	data->old_time = 0;
	data->speed = 1;
}
