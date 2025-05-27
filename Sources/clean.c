/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 13:28:50 by fabio             #+#    #+#             */
/*   Updated: 2025/05/28 00:06:19 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture_char(char **textures)
{
	int	n;

	n = 0;
	while (textures[n])
		free(textures[n++]);
	free(textures[n]);
	free(textures);
}

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

void clean_textures_arr(t_data *data, t_texture *texture)
{
	int n;

	n = 0;
	while (n < 4)
	{
		if ((texture[n]).t_img != NULL)
			mlx_destroy_image(data->mlx, texture[n].t_img);
		n++;
	}
}

int	delete_everything(t_data *data)
{
	clean_map(data->map);
	clean_textures(data->map);
	clean_textures_arr(data, data->texture);
	clean_textures_arr(data, data->sprite);
	if (data->img != NULL)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx_win != NULL)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx != NULL)
	{
		mlx_do_key_autorepeaton(data->mlx);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(0);
}
