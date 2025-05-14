/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file_cub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:19:49 by fabio             #+#    #+#             */
/*   Updated: 2025/05/14 11:11:16 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	got_all_textures(t_map *map)
{
	if (!map->no || !map->so || !map->ea || !map->we)
		return (0);
	if ((map->ceiling[0] < 0 || map->ceiling[0] > 255)
		|| (map->ceiling[1] < 0 || map->ceiling[1] > 255)
		|| (map->ceiling[2] < 0 || map->ceiling[2] > 255))
		return (0);
	if ((map->floor[0] < 0 || map->floor[0] > 255)
		|| (map->floor[1] < 0 || map->floor[1] > 255)
		|| (map->floor[2] < 0 || map->floor[2] > 255))
		return (0);
	return (1);
}

static int	getting_info(t_map *map, int fd)
{
	char	*line;

	while (!got_all_textures(map))
	{
		line = get_next_line(fd);
		if (!line)
			return (1);
		if (ft_strncmp (line, "\n", 1))
			check_which_texture(map, line);
		free(line);
	}
	map->textures[0] = map->no;
	map->textures[1] = map->so;
	map->textures[2] = map->we;
	map->textures[3] = map->ea;
	return (0);
}

static void	alloc_map(t_map *map, char *line, int fd)
{
	int	x;
	int	y;

	y = 0;
	map->char_map = malloc(sizeof(char *) * 2);
	if (!map->char_map)
		return ;
	map->char_map[0] = ft_strdup(line);
	map->char_map[1] = 0;
	while (line)
	{
		x = ft_strlen(line);
		if (x > map->max_x)
			map->max_x = x;
		y++;
		free(line);
		line = get_next_line(fd);
	}
	map->max_y = y;
	map->max_x -= 1;
}

static int	get_rest_of_the_map(t_map *map, int fd2)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd2);
	while (ft_strcmp(line, map->char_map[0]))
	{
		free(line);
		line = get_next_line(fd2);
	}
	free_char_array(map->char_map);
	map->char_map = malloc(sizeof(char *) * (map->max_y + 1));
	map->char_map[i] = line;
	while (map->char_map[i])
	{
		if (!ft_strcmp(map->char_map[i], "\n"))
		{
			free(map->char_map[i]);
			map->char_map[i] = 0;
			return (1);
		}
		map->char_map[++i] = get_next_line(fd2);
	}
	return (0);
}

int	check_file(t_map *map, char *path)
{
	int		fd;
	int		fd2;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	fd2 = open(path, O_RDONLY);
	if (fd2 == -1)
		return (0);
	if (getting_info(map, fd))
		return (0);
	line = get_next_line(fd);
	while (!ft_strcmp(line, "\n"))
	{
		free (line);
		line = get_next_line(fd);
	}
	alloc_map(map, line, fd);
	if (get_rest_of_the_map(map, fd2))
		return (0);
	close(fd);
	close(fd2);
	return (1);
}
