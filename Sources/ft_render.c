/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:25:29 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/26 18:30:00 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int resting_sprite()
{

}

/* int moving_sprite()
{

} */

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	ft_movement(data);
	create_image(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	if (ft_movement_verifier(data))
		resting_sprite();
/* 	else
		moving_sprite(); */
	display_fps(data);
	return (0);
}
