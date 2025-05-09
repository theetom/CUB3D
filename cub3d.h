/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:02:37 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/09 15:17:01 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

# include "minilibx-linux/mlx.h"
# include "Libft/libft.h"
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

enum DIR{
	EAST,
	WEST,
	SOUTH,
	NORTH
};

typedef struct s_map
{
	char 	**char_map; //alloc
	int		**int_map;	////alloc
	int		max_x;
	int		max_y;
	char	player_direction;
	float	p_x;
	float	p_y;
	int		floor[2];  //alloc
	int		ceiling[2]; //alloc
	char	*no; //alloc
	char	*so; //alloc
	char	*we; //alloc
	char	*ea; //alloc
	char	**textures; //alloc
}			t_map;

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
	int		wall_dir;

	int		hit;
	int		side;
}	t_math;


typedef struct s_texture
{
	void	*t_img;
	int		t_height;
	int		t_width;
	int		bit_p_pixel;
	int		size_line;
	int		endian;
	char *addr;
}	t_texture;


typedef struct s_data
{
	t_texture	texture[4];
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

t_texture	import_texture(t_data *data, char *xpm_file_path);
int	get_color_from_image(int x, int y, t_texture *texture);
void	get_textures_from_xpm(t_data *data, char **textures);
void	ft_hooks(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_vertical_line(int x, int start, int end, int color, t_data *data);
int			create_image(t_data *data);
void		ray_dda(t_math *math, t_data *data);
void		init_math(t_data *data, t_math *math, int x);
void		find_ray_angle(t_math *math, t_data *data);
void		draw_column(t_data *data, t_math *math, int x, int h);


//	TIME

void		display_fps(t_data *data);
double		getTicks(void);


// parsing

int 	parsing_map(int argc, char **argv, t_map *map);
int		check_file(t_map *map, char *path);
void	check_which_texture(t_map *map, char *str);
void	free_char_array(char **strs);
int		check_player_info(t_map *map);
int		check_map_input(char **map);
int 	check_if_closed(char **map);
int 	copy_map_to_int(t_map *map);

# endif
