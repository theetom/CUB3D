/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimColor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:18:52 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/11 14:19:49 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ColorRGB dimColor(t_ColorRGB color)
{
    color.r /= 2;
	color.g /= 2;
	color.b /= 2;
    return (color);
}