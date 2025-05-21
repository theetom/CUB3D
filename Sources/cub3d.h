/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toferrei <toferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 00:02:37 by toferrei          #+#    #+#             */
/*   Updated: 2025/05/21 22:47:40 by toferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
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

enum e_DIR
{
	EAST,
	WEST,
	SOUTH,
	NORTH
};

typedef struct s_map
{
	char		**char_map; //alloc
	int			**int_map;	////alloc
	int			max_x;
	int			max_y;
	char		player_direction;
	float		p_x;
	float		p_y;
	int			floor[3];
	int			ceiling[3];
	char		*no; //alloc
	char		*so; //alloc
	char		*we; //alloc
	char		*ea; //alloc
	char		**textures; //alloc
}				t_map;

typedef struct s_column
{
	int			line_h;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
}				t_column;

typedef struct s_math
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			wall_dir;
	int			hit;
	int			side;
}				t_math;

typedef struct s_texture
{
	void		*t_img;
	int			t_height;
	int			t_width;
	int			bit_p_pixel;
	int			size_line;
	int			endian;
	char		*addr;
}	t_texture;

typedef struct s_data
{
	int			strafe;
	int			move;
	int			rotate;
	int			mouse;
	int			debug;
	t_texture	texture[4];
	t_map		*map;
	void		*img;
	void		*mlx;
	void		*mlx_win;
	char		*addr;
	int			img_h;
	int			img_w;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		move_speed;
	double		rot_speed;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y; //initial direction vector
	double		plane_x;
	double		plane_y; //the 2d raycaster version of camera plane
	double		time; //time of current frame
	double		old_time; //time of previous frame
	int			**world_map;
	int			speed;
}	t_data;

typedef struct s_ColorRGB
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_ColorRGB;

void		draw_minimap(t_data *data);
int			color_atoi(t_ColorRGB color);

void		ft_data_init(t_data *data, t_map *map);
int			get_color_from_image(int x, int y, t_texture *texture);
int			get_textures_from_xpm(t_data *data, char **textures);
void		ft_hooks(t_data *data);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			create_image(t_data *data);
void		ray_dda(t_math *math, t_data *data);
void		init_math(t_data *data, t_math *math, int x);
void		find_ray_angle(t_math *math, t_data *data);
void		draw_column(t_data *data, t_math *math, int x, int h);
int			color_arr_int(int a, int b, int c);
int			render(t_data *data);
void		ft_movement(t_data *data);
void		convert_orientation(t_data *data, char pos);
void		draw_ceiling(t_data *data, int end, int *y, int x);
void		draw_floor(t_data *data, int end, int *y, int x);

//	Time

void		display_fps(t_data *data);
double		get_ticks(void);

//	Parsing

int			parsing_map(int argc, char **argv, t_map *map);
int			check_file(t_map *map, char *path);
void		check_which_texture(t_map *map, char *str);
void		free_char_array(char **strs);
int			check_player_info(t_map *map);
int			check_map_input(char **map);
int			check_if_closed(char **map);
int			copy_map_to_int(t_map *map);
int			check_if_double(t_map *map, char *str);
int 		check_textures(char **textures);

//	Clean
void		free_texture_char(char **textures);
void		clean_textures(t_map *map);
void		clean_map(t_map *map);
int			delete_everything(t_data *data);

#endif
