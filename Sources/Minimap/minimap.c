/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 22:59:08 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 13:36:58 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_minimap(t_data *data)
{
	t_minimap	minimap;

	minimap = *(data->minimap);
	draw_map(data, &minimap);
	draw_player(data, &minimap);
}
