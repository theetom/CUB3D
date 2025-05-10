/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:28:50 by fabio             #+#    #+#             */
/*   Updated: 2025/05/10 14:20:45 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_textures(t_map *map)
{
	if (map->no)
		free(map->no);
	if (map->so)
		free(map->so);
	if (map->we)
		free(map->we);
	if (map->ea)
		free(map->ea);
	free(map->textures);
}

void	clean_map(t_map *map)
{
	int i;

	if (map->char_map)
		free_char_array(map->char_map);
	if (map->int_map)
	{
		i = 0;
		while (i < map->max_y)
			free(map->int_map[i++]);
		free(map->int_map);
	}
}

int	delete_everything(t_data *data)
{
	clean_map(data->map);
	mlx_destroy_image(data->mlx, data->texture[0].t_img);
	mlx_destroy_image(data->mlx, data->texture[1].t_img);
	mlx_destroy_image(data->mlx, data->texture[2].t_img);
	mlx_destroy_image(data->mlx, data->texture[3].t_img);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
