/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 16:12:57 by fabio             #+#    #+#             */
/*   Updated: 2025/05/09 01:01:43 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parsing_error_msg(char *msg)
{
	printf("%s\n", msg);
	return (1);
}

static int check_map(t_map *map, char *path)
{
	int i;

	if (!path)
		return (1);
	i = 0;
	while (path[i] && path[i] != '.')
		i++;
	if (ft_strcmp(path + i, ".cub"))
		return (parsing_error_msg("Not a .cub file"));
	if (!check_file(map, path))
		return (parsing_error_msg("Invalid inputs in textures"));
	if (!check_player_info(map))
		return (parsing_error_msg("No player or multiple players found"));
	if (!check_map_input(map->char_map))
		return (parsing_error_msg("Invalid map inputs"));
	if (!check_if_closed(map->char_map))
		return (parsing_error_msg("Map not closed or invalid 0"));
	if (!copy_map_to_int(map))
		return (parsing_error_msg("Failed copying INT map"));
	return (0);
}

static void init_map(t_map *map)
{
	map->char_map = NULL;
	map->int_map = NULL;
	map->max_x = 0;
	map->max_y = 0;
	map->player_direction = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->floor[0] = -1;
	map->floor[1] = -1;
	map->floor[2] = -1;
	map->ceiling[0] = -1;
	map->ceiling[1] = -1;
	map->ceiling[2] = -1;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->textures = malloc(sizeof(char *) * 5);
	map->textures[4] = 0;
}

int parsing_map(int argc, char **argv, t_map *map)
{
	if (argc != 2)
	{
		printf("Not enough arguments!!\n");
		return (1);
	}
	init_map(map);
	if (check_map(map, argv[1]) == 1)
	{
		printf("Error in parsing\n");
		return (1);
	}
	return (0);
}
