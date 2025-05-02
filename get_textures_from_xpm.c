/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_from_xpm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:03:22 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/02 18:20:43 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures_from_xpm(t_data *data, char **textures)
{
	int i;

	while(textures[i])
	{
		if (textures[i][0] != '\0')
		{
			data->texture[i] = import_texture(data, textures[i]);
		}
		else
		{

			//give default texture
		}
		i++;
	}
}