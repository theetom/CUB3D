/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_hooks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:56:11 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/23 12:56:29 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_minimap_hooks(int k, t_minimap *minimap)
{
	if (k == 65450)
		minimap->hook_flag ^= 1;
	if (minimap->hook_flag == 0 && k == 65451)
		minimap->tile_size += 1;
	if (minimap->hook_flag == 0 && k == 65453)
		minimap->tile_size -= 1;
	if (minimap->hook_flag == 1 && k == 65451)
		minimap->player_size += 1;
	if (minimap->hook_flag == 1 && k == 65453)
		minimap->player_size -= 1;
	return (0);
}
