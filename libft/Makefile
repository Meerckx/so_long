# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 16:48:14 by tbaharat          #+#    #+#              #
#    Updated: 2022/02/15 19:59:17 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:=	libft.a


INC_DIR			:=	includes
SRC_DIR			:=	src
OBJ_DIR			:=	obj

LIBFT_DIR		:=	libft
PRINTF_DIR		:=	printf
GNL_DIR			:=	gnl

INCLUDE			:=	libft.h ft_printf.h get_next_line.h
INCLUDE			:=	$(addprefix $(INC_DIR)/, $(INCLUDE))

LIBFT_FILES		:=	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
					ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
					ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c\
					ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
					ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
					ft_tolower.c ft_toupper.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
					ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

PRINTF_FILES	:=	ft_char_type.c ft_hex_type.c ft_intdec_type.c ft_is_check.c ft_minus_flag.c ft_parsing.c\
					ft_percent_type.c ft_plus_flag.c ft_pointer_type.c ft_precision_flags.c ft_print_list.c\
					ft_printf.c ft_processor.c ft_sharp_flag.c ft_space_flag.c ft_specifier_error.c\
					ft_specifier_parsing.c ft_str_type.c ft_uint_type.c ft_width_flags.c ft_zero_flag.c ft_hex_init.c\
					ft_printf_itoa.c ft_itoa_uint.c

GNL_FILES		:=	get_next_line.c get_next_line_utils.c

SRC				:=	$(addprefix $(SRC_DIR)/$(LIBFT_DIR)/, $(LIBFT_FILES))
SRC				:=	$(SRC) $(addprefix $(SRC_DIR)/$(PRINTF_DIR)/, $(PRINTF_FILES))
SRC				:=	$(SRC) $(addprefix $(SRC_DIR)/$(GNL_DIR)/, $(GNL_FILES))

OBJ				:=	$(SRC:.c=.o)

CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror

.PHONY : all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c $(INCLUDE)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
