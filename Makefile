# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgranja <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 15:09:13 by cgranja           #+#    #+#              #
#    Updated: 2022/03/01 16:00:37 by user42           ###   ########.fr        #
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
			mlx_start.c \
			#moveplayer.c \

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

RM		=	/usr/bin/rm -f

CFLAGS		=	-Wall -Wextra -Werror

CFS			=	-fsanitize=address -g3


all		:	$(NAME)


$(NAME) :	$(OBJ)
			make -C minilibx-linux
			$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LIB)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)
			make -C minilibx-linux clean

norm	:
			norminette $(SRC)
			norminette so_long.h

re		:	fclean all

f 		:	mlx $(OBJ)
			make -C minilibx-linux
			$(CC) $(CFLAGS) $(CFS) -o $(NAME) $(SRC) $(LIB)

fre		:	fclean f

.PHONY : all mlx clean fclean re f fre norm



