/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:21:59 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/16 01:15:03 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_atoi(t_ColorRGB color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

int	color_arr_int(int a, int b, int c)
{
	return (a << 16 | b << 8 | c);
}
