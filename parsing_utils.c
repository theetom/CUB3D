/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:52:24 by fabio             #+#    #+#             */
/*   Updated: 2025/05/09 16:34:19 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	fetch_player_direction(t_map *map, int y, int x)
{
	map->p_x = x + 0,5;
	map->p_y = y + 0.5;
	map->player_direction = map->char_map[y][x];
	map->char_map[y][x] = '0';
}

int	check_player_info(t_map *map)
{
	int	i;
	int	j;
	char **temp;

	i = 0;
	temp = map->char_map;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][j] == 'N' || temp[i][j] == 'S' ||
				temp[i][j] == 'W' || temp[i][j] == 'E')
			{
				if (map->player_direction != 0)
					return (0);
				fetch_player_direction(map, i, j);
			}
			j++;
		}
		i++;
	}
	if (map->player_direction == 0)
		return (0);
	return (1);
}

int	check_map_input(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' &&
				map[i][j] != ' ' && map[i][j] != '\n')
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int check_if_closed(char **map)
{
	int x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				if (!map[y + 1] || !map[y + 1][x] || map[y + 1][x] == ' ')
					return (0);
				if (y == 0  || !map[y - 1] || map[y - 1][x] == ' ')
					return (0);
				if (!map[y][x + 1] || map[y][x + 1] == ' ')
					return (0);
				if (x == 0 || map[y][x - 1] == ' ')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int copy_map_to_int(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	map->int_map = malloc(sizeof(int *) * map->max_y);
	if (!map->int_map)
		return (0);
	while (map->char_map[y])
	{
		x = 0;
		map->int_map[y] = ft_calloc(ft_strlen(map->char_map[y]), sizeof(int));
		if (!map->int_map[y])
			return (0);
		while (map->char_map[y][x] && map->char_map[y][x] != '\n')
		{
			if (map->char_map[y][x] == '0' || map->char_map[y][x] == '1')
			{
				map->int_map[y][x] = map->char_map[y][x] - '0';
			}
			else
				map->int_map[y][x] = 2;
			// printf("%d", map->int_map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	return (1);
}
