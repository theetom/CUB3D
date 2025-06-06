# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 16:37:07 by toferrei          #+#    #+#              #
#    Updated: 2025/05/23 13:40:19 by toferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D

LIBFT		=	Libft/
LIBFT_A		=	$(LIBFT)libft.a

OBJ_DIR		=	Objects/

SRC			=	Sources/

HKS			=	Hooks/
MMP			=	Minimap/

SOURCES		=	$(SRC)$(MMP)minimap.c \
				$(SRC)$(MMP)draw_tile.c \
				$(SRC)$(MMP)draw_map.c \
				$(SRC)$(MMP)draw_player.c \
				$(SRC)$(HKS)ft_hooks.c \
				$(SRC)$(HKS)minimap_hooks.c \
				$(SRC)$(HKS)mouse_hook.c \
				$(SRC)$(HKS)movement_hooks.c \
				$(SRC)clean.c \
				$(SRC)color_atoi.c \
				$(SRC)create_image.c \
				$(SRC)draw_column.c \
				$(SRC)draw_floor_ceiling.c \
				$(SRC)find_ray_angle.c \
				$(SRC)ft_movement.c \
				$(SRC)ft_move_rotate.c \
				$(SRC)ft_move_strafe.c \
				$(SRC)ft_move_up_down.c \
				$(SRC)ft_render.c \
				$(SRC)get_textures_from_xpm.c \
				$(SRC)get_ticks.c \
				$(SRC)init_data.c \
				$(SRC)init_math.c \
				$(SRC)main.c \
				$(SRC)my_pixel_put.c \
				$(SRC)orientation.c \
				$(SRC)parsing_file_cub.c \
				$(SRC)parsing_textures.c \
				$(SRC)parsing_utils.c \
				$(SRC)parsing_utils2.c \
				$(SRC)parsing.c \
				$(SRC)ray_dda.c \
				$(SRC)time.c



OBJECTS		=	$(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SOURCES))

# Compiler and Flags
CC			=	gcc
CFLAGS		=	-g -Wall -Wextra -Werror
LDFLAGS		=	-L$(LIBFT) -lft
MLXFLAGS	=	-I/usr/include -Iminiliblibx-linux -O3 -Lminilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm

# Default Target
all: $(NAME)

# Build the executable
$(NAME): $(OBJECTS)
	@$(MAKE) -s -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LDFLAGS) $(MLXFLAGS)
	@echo "All files were created"

# Rule for building object files
$(OBJ_DIR)%.o: $(SRC)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@rm -f $(OBJECTS)
	@rm -rf $(OBJ_DIR)
	@echo "Object files were cleaned"

# Full clean
fclean: clean
	@$(MAKE) -s -C $(LIBFT) clean
	@rm -f $(NAME)
	@echo "All files were cleaned"

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re
