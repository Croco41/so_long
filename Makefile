# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgranja <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 15:09:13 by cgranja           #+#    #+#              #
#    Updated: 2021/12/20 15:33:48 by cgranja          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

LIB		=	-L minilibx-linux -lmlx -lXext -lX11 -lm

SRC		=	main.c \
			error.c \
			check.c \
			parsing.c \
			free.c \
			init_struct.c \
			utils/ft_str_comp.c \
			utils/ft_strlen.c \
			utils/ft_strdup.c \
			utils/get_next_line.c \
			utils/get_next_line_utils.c \
#			mlx_start.c \

OBJ		=	$(SRC:%.c=%.o)

CC		=	gcc

RM		=	/usr/bin/rm -f
$(MAKE) = /usr/bin/make
CFLAGS		=	-Wall -Wextra -Werror

CFS			=	-fsanitize=address -g3


all		:	$(NAME)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	mlx $(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

mlx		:
			$(MAKE) -C minilibx-linux

clean	:
			$(MAKE) -C minilibx-linux clean
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

#norm	:
#			norminette $(SRC)
#			norminette push_swap.h

re		:	fclean all

f 		:	mlx $(OBJ)
			$(CC) $(CFLAGS) $(CFS) -o $(NAME) $(SRC) $(LIB)

fre		:	fclean f

.PHONY : all mlx clean fclean re f fre 



