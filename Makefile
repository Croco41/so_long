# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgranja <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 15:09:13 by cgranja           #+#    #+#              #
#    Updated: 2021/12/14 16:27:10 by cgranja          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

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
			testmap.ber \

OBJ		=	$(SRC:%.c=%.o)

CC		=	gcc

RM		=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

CFS			=	-fsanitize=address -g3

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRC)

all		:	$(NAME)

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

#norm	:
#			norminette $(SRC)
#			norminette push_swap.h

re		:	fclean all

f 		:	$(OBJ)
			$(CC) $(CFLAGS) $(CFS) -o $(NAME) $(SRC)

fre		:	fclean f

.PHONY : clean fclean re fre 



