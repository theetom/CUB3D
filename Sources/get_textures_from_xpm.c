/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures_from_xpm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:03:22 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/29 09:29:34 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	import_texture(t_data *data, char *xpm_file_path, \
							t_texture *texture)
{
	texture->t_img = mlx_xpm_file_to_image(data->mlx, \
										xpm_file_path, \
										&(texture->t_width), \
										&(texture->t_height));
	if (texture->t_img == 0)
		return (0);
	texture->addr = mlx_get_data_addr(texture->t_img, \
										&(texture->bit_p_pixel), \
										&(texture->size_line), \
										&(texture->endian));
	if (texture->addr == 0)
		return (0);
	return (1);
}

int	get_textures_from_xpm(t_data *data, char **t_path, t_texture *texture)
{
	int	i;

	i = 0;
	while (t_path[i])
	{
		printf("path :%s\n", t_path[i]);
		if (import_texture(data, t_path[i], &(texture[i])) == 0)
			return (0);
		i++;
	}
	return (1);
}
