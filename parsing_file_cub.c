/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_cub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:19:49 by fabio             #+#    #+#             */
/*   Updated: 2025/05/04 15:28:48 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int got_all_textures(t_map *map)
{
	if (map->no && map->so && map->ea && map->we
		&& map->floor[2] >= 0 && map->ceiling[2] >= 0
		&& map->floor[1] >= 0 && map->ceiling[1] >= 0
		&& map->floor[0] >= 0 && map->ceiling[0] >= 0)
		return (1);
	return (0);
}

static int	getting_textures(t_map *map, int fd)
{
	char *line;

	while (!got_all_textures(map))
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (ft_strncmp (line, "\n", 1))
			check_which_texture(map, line);
	}
	return (0);
}

int	check_file(t_map *map, char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	if (getting_textures(map, fd))
		return (0);
	close(fd);
	return (1);
}
