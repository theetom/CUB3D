/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:02:37 by toferrei          #+#    #+#             */
/*   Updated: 2025/04/15 12:21:31 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define _OPEN_SYS_ITOA_EXT
# define mapWidth 6
# define mapHeight 6

typedef struct s_math
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;

	int		hit;
	int		side;
}	t_math;


typedef struct s_data
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			img_h;
	int			img_w;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		moveSpeed;
	double		rotSpeed;

	double 		posX, posY;  //x and y start position
	double 		dirX, dirY; //initial direction vector
	double 		planeX, planeY; //the 2d raycaster version of camera plane
  
	double 		time; //time of current frame
	double 		oldTime; //time of previous frame

	int			**worldMap;

}	t_data;

typedef struct s_ColorRGB
{
	unsigned char r, g, b;
}	t_ColorRGB;

t_ColorRGB	dimColor(t_ColorRGB color);
int			color_atoi(t_ColorRGB color);

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_vertical_line(int x, int start, int end, int color, t_data *data);
double		getTicks(void);
int			create_image(t_data *data);
void		ray_dda(t_math *math, t_data *data);
void		init_math(t_data *data, t_math *math, int x);
void		find_ray_angle(t_math *math, t_data *data);
void		draw_column(t_data *data, t_math *math, int x, int h);


# endif