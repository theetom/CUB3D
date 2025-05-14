/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:57:11 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/14 11:08:37 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ColorRGB	get_color(t_math *math)
{
	if (math->wall_dir == 0)
		return ((t_ColorRGB){255, 0, 0});
	else if (math->wall_dir == 1)
		return ((t_ColorRGB){255, 0, 255});
	else if (math->wall_dir == 2)
		return ((t_ColorRGB){255, 255, 255});
	else
		return ((t_ColorRGB){255, 255, 0});
}
