/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 16:30:22 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 10:04:47 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_data_init(t_data *data)
{
	data->world_map = data->map->int_map;
	data->pos_x = data->map->p_x;
	data->pos_y = data->map->p_y;
	data->debug = 0;
	data->time = 0;
	data->old_time = 0;
	data->speed = 1;
	ft_bzero(data->minimap, sizeof *(data->minimap));
	data->minimap->color = 0x222222;
	data->minimap->tile_size = 10;
	data->minimap->player_size = 5;
	data->minimap->pos_x = 20;
	data->minimap->pos_y = 20;
}
