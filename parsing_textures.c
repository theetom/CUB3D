/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabio <fabio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:23:45 by fabio             #+#    #+#             */
/*   Updated: 2025/05/10 13:43:35 by fabio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*check_spaces(char * str)
{
	while (*str == ' ')
		*str++;
	return (str);
}

void	free_char_array(char **strs)
{
	int	i;

	if (!strs)
		return;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

static int check_if_valid_input(char **numbers)
{
	int i;
	int j;

	i = 0;
	while (numbers[i])
	{
		j = 0;
		if (i == 0)
			j += 2;
		while (numbers[i][j] == ' ')
			j++;
		while (numbers[i][j] && numbers[i][j] != '\n')
		{
			if (!ft_isdigit(numbers[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

static void	get_RGB(t_map *map, char *str)
{
	char **numbers;

	numbers = ft_split(str, ',');
	if (!numbers)
		return ;
	if (check_if_valid_input(numbers))
	{
		free_char_array(numbers);
		return ;
	}
	if (ft_strncmp(str, "F ", 2) == 0)
	{
		map->floor[0] = ft_atoi(numbers[0] + 1);
		map->floor[1] = ft_atoi(numbers[1]);
		map->floor[2] = ft_atoi(numbers[2]);
	}
	if (ft_strncmp(str, "C ", 2) == 0)
	{
		map->ceiling[0] = ft_atoi(numbers[0] + 1);
		map->ceiling[1] = ft_atoi(numbers[1]);
		map->ceiling[2] = ft_atoi(numbers[2]);
	}
	free_char_array(numbers);
}

void	check_which_texture(t_map *map, char *str)
{
	while (*str == ' ')
		str++;
	if (ft_strncmp(str, "SO ", 3) == 0)
	{
		map->so = ft_substr(str, 3, ft_strlen(str) - 4);
		map->so = check_spaces(map->so);
	}
	else if (ft_strncmp(str, "NO ", 3) == 0)
	{
		map->no = ft_substr(str, 3, ft_strlen(str) - 4);
		map->no = check_spaces(map->no);
	}
	else if (ft_strncmp(str, "WE ", 3) == 0)
	{
		map->we = ft_substr(str, 3, ft_strlen(str) - 4);
		map->we = check_spaces(map->we);
	}
	else if (ft_strncmp(str, "EA ", 3) == 0)
	{
		map->ea = ft_substr(str, 3, ft_strlen(str) - 4);
		map->ea = check_spaces(map->ea);
	}
	else if (ft_strncmp(str, "C ", 2) == 0 || ft_strncmp(str, "F ", 2) == 0)
		get_RGB(map, str);
}
