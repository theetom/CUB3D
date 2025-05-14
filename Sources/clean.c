/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:28:50 by fabio             #+#    #+#             */
/*   Updated: 2025/05/14 16:02:13 by toferrei         ###   ########.fr       */
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
	int	i;

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
	int n;

	n = 0;
	mlx_do_key_autorepeaton(data->mlx);
	clean_map(data->map);
	clean_textures(data->map);
	while (n < 4)
	{
		if (data->texture[n].t_img != NULL)
			mlx_destroy_image(data->mlx, data->texture[n].t_img);
		n++;
	}
	printf("ola\n");
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}
