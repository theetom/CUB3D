# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <sys/time.h>

# define mapWidth 24
# define mapHeight 24

/* 




VER https://harm-smits.github.io/42docs/projects/cub3d

*/

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	char	*addr;
	int		img_h;
	int		img_w;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	double posX, posY;  //x and y start position
	double dirX, dirY; //initial direction vector
	double planeX, planeY; //the 2d raycaster version of camera plane
  
	double time; //time of current frame
	double oldTime; //time of previous frame
	double moveSpeed;
	double rotSpeed;

}	t_data;

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
  };

typedef struct {
    unsigned char r, g, b;
} ColorRGB;

// Define color constants
const ColorRGB RGB_Red    = {255, 0, 0};
const ColorRGB RGB_Green  = {0, 255, 0};
const ColorRGB RGB_Blue   = {0, 0, 255};
const ColorRGB RGB_White  = {255, 255, 255};
const ColorRGB RGB_Yellow = {255, 255, 0};

// Function to reduce brightness
ColorRGB dimColor(ColorRGB color)
{
    color.r /= 2;
    color.g /= 2;
    color.b /= 2;
    return color;
}
int color_from_c_to_int(ColorRGB color)
{
	return(color.r << 24| color.g << 16 | color.b << 8 | 100);
}

double getTicks()
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000.0) + (tv.tv_usec / 1000.0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/* void ola()
{

} */

int	game_loop(t_data *data)
{
	int x = 0;
	char fps_text[100], speed_text[100];

	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	data->time = getTicks();

    double frameTime = (data->time - data->oldTime) / 1000.0;
    data->oldTime = data->time;
	if (frameTime > 0)
	{
        sprintf(fps_text, "FPS: %.2f", 1.0 / frameTime);
    }
	else
	{
        sprintf(fps_text, "FPS: --");
    }

    // Speed modifiers
    data->moveSpeed = frameTime * 5.0;
    data->rotSpeed = frameTime * 3.0;
	sprintf(speed_text, "Move Speed: %.5f, Rot Speed: %.5f", data->moveSpeed, data->rotSpeed);
	while (x < data->img_w)
	{
		double cameraX = 2 * x / data->img_w - 1; //x-coordinate in camera space
		double rayDirX = data->dirX + data->planeX * cameraX;
		double rayDirY = data->dirY + data->planeY * cameraX;
		int mapX = (int)data->posX;
		int mapY = (int)data->posY;
		double sideDistX;
		double sideDistY;
		double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1.0 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1.0 / rayDirY);
		double perpWallDist;

		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
  
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
		}
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
		}
		//perform DDA
		while(hit == 0)
		{
		//jump to next map square, either in x-direction, or in y-direction
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if(worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		if(side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);
		int lineHeight = (int)(data->img_h / perpWallDist);
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + data->img_h / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + data->img_h / 2;
		if(drawEnd >= data->img_h)
			drawEnd = data->img_h - 1;
		ColorRGB color;
		switch(worldMap[mapX][mapY])
		{
			case 1:  color = RGB_Red;    break;
			case 2:  color = RGB_Green;  break;
			case 3:  color = RGB_Blue;   break;
			case 4:  color = RGB_White;  break;
			default: color = RGB_Yellow; break;
		}
	
		// Give x and y sides different brightness
		if (side == 1) {
			color = dimColor(color);
		}
		int y = drawStart;
		printf("end %d start %d\n", drawEnd, drawStart);
		while (y < drawEnd)
		{
			my_mlx_pixel_put(data, x, y, color_from_c_to_int(color));
			y++;
		}
		x++;
	}
	data->oldTime = data->time;

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_string_put(data->mlx, data->mlx_win, 10, 20, 0xFFFFFF, fps_text);
    mlx_string_put(data->mlx, data->mlx_win, 10, 40, 0xFFFFFF, speed_text);
}

/* static void	render(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	create_image(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
} */

int delete_everything(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

bool is_wall(t_data *data, double x, double y)
{
    int mapX = (int)x;
    int mapY = (int)y;
    return (worldMap[mapX][mapY]);
}

int	keypress(int k, t_data *data)
{ 
	if (k == 0xff1b) // esc
		delete_everything(data);
	if (k == 119) // w
	{
		if (!is_wall(data, data->posX + data->dirX * data->moveSpeed, data->posY))
            data->posX += data->dirX * data->moveSpeed;
        if (!is_wall(data, data->posX, data->posY + data->dirY * data->moveSpeed))
            data->posY += data->dirY * data->moveSpeed;
	}
	if (k == 115) // s
	{
		if (!is_wall(data, data->posX - data->dirX * data->moveSpeed, data->posY))
			data->posX -= data->dirX * data->moveSpeed;
		if (!is_wall(data, data->posX, data->posY - data->dirY * data->moveSpeed))
			data->posY -= data->dirY * data->moveSpeed;
	}
	if (k == 100) // D
    {
        double oldDirX = data->dirX;
        data->dirX = data->dirX * cos(-data->rotSpeed) - data->dirY * sin(-data->rotSpeed);
        data->dirY = oldDirX * sin(-data->rotSpeed) + data->dirY * cos(-data->rotSpeed);
        double oldPlaneX = data->planeX;
        data->planeX = data->planeX * cos(-data->rotSpeed) - data->planeY * sin(-data->rotSpeed);
        data->planeY = oldPlaneX * sin(-data->rotSpeed) + data->planeY * cos(-data->rotSpeed);
    }
    if (k == 97) // A
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
	data->img = mlx_new_image(data->mlx, data->img_w, data->img_h);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
}

int main(int argc, char *argv[])
{
	t_data	data;

	data.img_h = 480;
	data.img_w = 640;
	data.posX = 22, data.posY = 12;  //x and y start position
	data.dirX = -1, data.dirY = 0; //initial direction vector
	data.planeX = 0, data.planeY = 0.66; //the 2d raycaster version of camera plane
  
	data.time = 0; //time of current frame
	data.oldTime = 0; //time of previous frame
	
	mlx_data_init(&data);
	ft_hooks(&data);
	mlx_loop_hook(data.mlx, game_loop, &data);
/* 	create_image(&data); */
	mlx_loop(data.mlx);
}



/* [ cos(a) -sin(a) ]
[ sin(a)  cos(a) ] */