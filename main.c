/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:58:30 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/15 16:10:08 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_fps(t_data *data) /* put after put iamge to window because of mlx string put */
{
	double	frameTime;
	char	fps_text[50];
	char	speed_text[100];
	char	ptr[100];

	data->time = getTicks();

	printf("x : %f y : %f\n", data->posX, data->posY);

	frameTime = (data->time - data->oldTime) / 1000.0;
    data->oldTime = data->time;

	if (frameTime > 0) {
        sprintf(fps_text, "FPS: %.2f", 1.0 / frameTime);
    } else {
        sprintf(fps_text, "FPS: --");
    }


	data->moveSpeed = frameTime * 5.0;
    data->rotSpeed = frameTime * 3.0;
    sprintf(speed_text, "Move Speed: %.5f, Rot Speed: %.5f", data->moveSpeed, data->rotSpeed);
	mlx_string_put(data->mlx, data->mlx_win, 10, 20, 0x00FFFFFF, fps_text);
    mlx_string_put(data->mlx, data->mlx_win, 10, 40, 0x00FFFFFF, speed_text);
	sprintf(ptr, "dir x : %f dir y : %f", data->dirX, data->dirY);
	mlx_string_put(data->mlx, data->mlx_win, 10, 60, 0x00FFFFFF, ptr);
	/* 	while (1 / frameTime > 90)
		{
			data->time = getTicks();
			frameTime = (data->time - data->oldTime) / 1000.0;
		} */
}

int	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	create_image(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	display_fps(data);
/* 	while (1 / frameTime > 90)
	{
		data->time = getTicks();
		frameTime = (data->time - data->oldTime) / 1000.0;
	} */
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
			data->posY -= data->dirY * data->moveSpeed;}
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
static void mlx_data_init(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->img_w, data->img_h, "My CUB3D!");
	ft_hooks(data);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

int main(int argc, char *argv[])
{
	t_data	data = {0};

	(void)argv;
	(void)argc;

	int row0[] = {1,1,1,1,1,1};
	int row1[] = {1,0,0,0,0,1};
	int row2[] = {1,1,0,0,0,1};
	int row3[] = {1,0,0,0,0,1};
	int row4[] = {1,0,0,0,0,1};
	int row5[] = {1,1,1,1,1,1};
	
	int *worldMap[] = {row0, row1, row2, row3, row4, row5};

	data.worldMap = worldMap;

	data.img_h = 1080 * 2;
	data.img_w = 1920 * 2;
	data.posX = 3, data.posY = 3;  //x and y start position
	data.dirX = -1, data.dirY = 0; //initial direction vector
	data.planeX = 0, data.planeY = 0.66; //the 2d raycaster version of camera plane
  
	data.time = 0; //time of current frame
	data.oldTime = 0; //time of previous frame


	mlx_data_init(&data);
	create_image(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}



/* [ cos(a) -sin(a) ]
[ sin(a)  cos(a) ] */