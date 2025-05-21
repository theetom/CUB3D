/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 22:30:19 by fabio             #+#    #+#             */
/*   Updated: 2025/05/21 01:01:46 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static int	check_if_double_rgb(t_map *map, char *str)
{
	if (ft_strncmp(str, "C ", 2) == 0)
	{
		if (map->ceiling[0] != -1)
			return (1);
	}
	else if (ft_strncmp(str, "F ", 2) == 0)
	{
		if (map->floor[0] != -1)
			return (1);
	}
	return (0);
}


int	check_if_double(t_map *map, char *str)
{
	if (ft_strncmp(str, "SO", 2) == 0)
	{
		if (map->so)
			return (1);
	}
	else if (ft_strncmp(str, "NO", 2) == 0)
	{
		if (map->no)
			return (1);
	}
	else if (ft_strncmp(str, "WE", 2) == 0)
	{
		if (map->we)
			return (1);
	}
	else if (ft_strncmp(str, "EA", 2) == 0)
	{
		if (map->ea)
			return (1);
	}
	else if (check_if_double_rgb(map, str))
		return (1);
	return (0);
}

int	check_textures(char **textures)
{
	int i;
	int j;

	i = 0;
	while (textures[i])
	{
		j = 0;
		while (textures[i][j])
		{
			if (textures[i][j] == ' ' || textures[i][j] == '	')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
