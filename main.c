/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:58:30 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/03 17:42:05 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	create_image(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	display_fps(data);
	return 0;
}

int delete_everything(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	keypress(int k, t_data *data)
{ 
	if (k == 0xff1b)
		delete_everything(data);
	if (k == 119) // frente
	{
		if(data->worldMap[(int)(data->posX + data->dirX)][(int)data->posY] == false)
			data->posX += data->dirX * data->moveSpeed;
		if(data->worldMap[(int)(data->posX)][(int)(data->posY + data->dirY)] == false)
			data->posY += data->dirY * data->moveSpeed;
	}
	if (k == 115) // tras
	{
		if(data->worldMap[(int)(data->posX - data->dirX)][(int)data->posY] == false)
			data->posX -= data->dirX * data->moveSpeed;
		if(data->worldMap[(int)(data->posX)][(int)(data->posY - data->dirY)] == false)
			data->posY -= data->dirY * data->moveSpeed;
	}
	if (k == 100) // direita
	{
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
		data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
      double oldPlaneX = data->planeX;
      data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
      data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
	}
	if (k == 97) // esquerda
	{
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(data->rotSpeed) - data->dirY * sin(data->rotSpeed);
		data->dirY = oldDirX * sin(data->rotSpeed) + data->dirY * cos(data->rotSpeed);
      double oldPlaneX = data->planeX;
      data->planeX = data->planeX * cos(data->rotSpeed) - data->planeY * sin(data->rotSpeed);
      data->planeY = oldPlaneX * sin(data->rotSpeed) + data->planeY * cos(data->rotSpeed);
	}
	return 0;
}

void	ft_hooks(t_data *data)
{
	mlx_hook(data->mlx_win, 02, (1L << 0), keypress, data);
	mlx_hook(data->mlx_win, 17, 1L << 17, delete_everything, data);
}
static int mlx_data_init(t_data *data)
{
	if ((data->mlx = mlx_init()) == NULL)
		return (0);
	mlx_get_screen_size(data->mlx, &data->img_w, &data->img_h);
	data->img_w /= 2;
	data->img_h /= 2;
	if ((data->mlx_win = mlx_new_window(data->mlx, data->img_w, data->img_h, "My CUB3D!")) == NULL)
		return (0);
	ft_hooks(data);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
	return (1);
}

t_texture	import_texture(t_data *data, char *xpm_file_path)
{
	t_texture texture;

	texture.t_img = mlx_xpm_file_to_image(data->mlx, xpm_file_path, \
		&(texture.t_width), &(texture.t_height));
	texture.addr = mlx_get_data_addr(texture.t_img, &(texture.bit_p_pixel), &(texture.size_line), &(texture.endian));
	return (texture);
}

int main(int argc, char *argv[])
{
	t_data	data = {0};

	(void)argv;
	(void)argc;

	int row0[] = {1,1,1,1,1,1,1,1,1,1,1,1};
	int row1[] = {1,0,0,0,0,0,0,1,0,0,0,1};
	int row2[] = {1,0,0,1,0,0,0,0,0,0,0,1};
	int row3[] = {1,0,0,0,0,1,1,0,0,0,0,1};
	int row4[] = {1,0,0,0,0,1,1,0,0,0,0,1};
	int row5[] = {1,0,1,0,0,1,1,0,0,0,0,1};
	int row6[] = {1,0,0,0,0,1,1,0,0,0,1,1};
	int row7[] = {1,0,0,1,1,0,0,1,1,0,0,1};
	int row8[] = {1,0,0,1,1,0,0,1,1,0,0,1};
	int row9[] = {1,0,0,0,0,0,0,0,0,0,0,1};
	int row10[] = {1,0,0,0,0,0,0,0,0,0,0,1};
	int row11[] = {1,1,1,1,1,1,1,1,1,1,1,1};
	
	
	int *worldMap[] = {row0, row1, row2, row3, row4, row5, row6, row7, row8, row9, row10, row11};

	data.worldMap = worldMap;

	data.posX = 4, data.posY = 3;  //x and y start position
	data.dirX = -1, data.dirY = 0; //initial direction vector
	data.planeX = 0, data.planeY = 0.66; //the 2d raycaster version of camera plane
	
	data.time = 0; //time of current frame
	data.oldTime = 0; //time of previous frame
	
	bool i;
	
	i = (bool)mlx_data_init(&data);
	if (i == false)
		return (1);
	

	data.texture = malloc(sizeof(t_texture) * 4);

	char *textures[] = {"./textures/AnyConv.com__BRICK_4A.xpm", \
		"./textures/AnyConv.com__SAND_1A.xpm", \
		"./textures/AnyConv.com__STEEL_1A.xpm", \
		"./textures/AnyConv.com__TECH_4E.xpm", NULL};
	

	printf("%d\n", data.texture[0].t_height);

	get_textures_from_xpm(&data, textures);
	create_image(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}



/* [ cos(a) -sin(a) ]
[ sin(a)  cos(a) ] */