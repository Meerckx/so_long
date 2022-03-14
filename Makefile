# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/13 14:40:51 by anonymous         #+#    #+#              #
#    Updated: 2022/03/06 15:57:41 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	so_long

INC_DIR			:=	include
LIBFT_INC_DIR	:=	includes


LIBFT_DIR		:=	libft
MLX_DIR			:=	minilibx-linux

HEADERS			:=	include/so_long.h include/structs.h $(LIBFT_DIR)/includes/ft_printf.h $(LIBFT_DIR)/includes/get_next_line.h\
					$(LIBFT_DIR)/includes/libft.h

LIBFT			:=	$(LIBFT_DIR)/libft.a
LIBMLX			:=	$(MLX_DIR)/libmlx.a

SRCS			:=	src/so_long.c src/end_game.c src/map_init.c src/start_game.c src/map_validation.c src/map_read.c\
					src/clear.c src/create_tiles.c src/render.c src/alloc_tilemap.c src/input.c src/moves.c\

SRCS_BONUS		:=	src_bonus/so_long_bonus.c src_bonus/end_game_bonus.c src_bonus/map_init_bonus.c src_bonus/start_game_bonus.c\
					src_bonus/map_validation_bonus.c src_bonus/map_read_bonus.c src_bonus/clear_bonus.c\
					src_bonus/create_tiles_bonus.c src_bonus/render_bonus.c src_bonus/alloc_tilemap_bonus.c\
					src_bonus/input_bonus.c src_bonus/moves_bonus.c src_bonus/animations_bonus.c

OBJS			:=	$(SRCS:%.c=%.o)
OBJS_B			:=	$(SRCS_BONUS:%.c=%.o)

D_FILES			:=	$(SRCS:%.c=%.d)
D_FILES_BONUS	:=	$(SRCS_BONUS:%.c=%.d)

CC				:=	cc
#CPPFLAGS		:=	-I $(INC_DIR) -I $(LIBFT_DIR)/$(LIBFT_INC_DIR) -I $(MLX_DIR) -MMD -MP
CFLAGS			:=	-O2 -Wall -Wextra -Werror
LDLIBS			:=	-lft -lmlx -lXext -lX11 -lm -lz

.PHONY : all bonus clean fclean re

all: $(NAME)

$(NAME) : $(LIBFT) $(LIBMLX) $(OBJS)
	$(CC) -L$(LIBFT_DIR) -L$(MLX_DIR) $(OBJS) $(LDLIBS) -o $(NAME)

$(LIBFT) :
	$(MAKE) --directory=$(LIBFT_DIR)

$(LIBMLX) :
	$(MAKE) --directory=$(MLX_DIR)

%.o : %.c $(HEADERS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

bonus :
	make SRCS="$(SRCS_BONUS)" all

clean :
	rm -rf $(OBJS) $(OBJS_B) $(D_FILES) $(D_FILES_BONUS)
	$(MAKE) clean --directory=$(LIBFT_DIR)
	$(MAKE) clean --directory=$(MLX_DIR)

fclean : clean
	rm -rf $(NAME)
	$(MAKE) fclean --directory=$(LIBFT_DIR)

re : fclean all
