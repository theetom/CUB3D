# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toferrei <toferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 16:37:07 by toferrei          #+#    #+#              #
#    Updated: 2025/05/12 16:41:21 by toferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME		=	minishell

# LIBFT		=	Libft/
# LIBFT_A		=	$(LIBFT)libft.a

# OBJ_DIR		=	Objects/

# SRC			=	Sources/

# BLT			=	Built_ins/
# ERR			=	Error_management/
# EXC			=	Executor/
# EXP			=	Expanse/
# INI			=	Initialization/
# LST			=	List_utils/
# PRS			=	Parsing/
# QOT			=	Quotes/
# RED			=	Redirections_handler/
# SGN			=	Signals/
# TOK			=	Tokens/

# SOURCES		=	

# OBJECTS		=	$(patsubst $(SRC)%.c, $(OBJ_DIR)%.o, $(SOURCES))

# # Compiler and Flags
# CC			=	cc
# LDFLAGS		=	-L$(LIBFT) -lft
# CFLAGS		=	-g -Wall -Wextra -Werror 
# RFLAGS		=	-lreadline

# # Default Target
# all: $(NAME)

# # Build the executable
# $(NAME): $(OBJECTS)
# 	@$(MAKE) -s -C $(LIBFT)
# 	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LDFLAGS) $(RFLAGS)
# 	@echo "All files were created"

# # Rule for building object files
# $(OBJ_DIR)%.o: $(SRC)%.c
# 	@mkdir -p $(dir $@)
# 	@$(CC) $(CFLAGS) -c $< -o $@

# # Clean object files
# clean:
# 	@rm -f $(OBJECTS)
# 	@rm -rf $(OBJ_DIR)
# 	@echo "Object files were cleaned"

# # Full clean
# fclean: clean
# 	@$(MAKE) -s -C $(LIBFT) clean
# 	@rm -f $(NAME)
# 	@echo "All files were cleaned"

# # Rebuild everything
# re: fclean all

# # Phony targets
# .PHONY: all clean fclean re

# v: re
# 	valgrind --suppressions=readline.supp --show-leak-kinds=all --leak-check=full --track-fds=yes ./minishell








# gcc -g *.c -I/usr/include -Iminiliblibx-linux -O3 -Lminilibx-linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz