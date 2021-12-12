/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:29:34 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/12 15:38:37 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"


typedef struct s_img
{
	void		*img;
	char		*addr;
	int			*img_width;
	int			*img_height;
	int			bitspp;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img		window;
	t_img		collectible;
	t_img		player;
	t_img		ground;
	t_img		wall;
	t_img		exit;
}				t_mlx;

typedef struct s_player
{
	int			move;
	int			x;
	int			y;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			nbcollecti;
	int			nbexit;
	int			nbplayer;
	int			nbline;
	t_player	player;
}				t_map;

typedef struct s_admin
{
	t_map		map;
	t_mlx		mlx
}				t_admin;


int		main(int argc, char **argv);
t_map	**ft_open_map(t_map **map, int fd);
int		ft_opencheckfile(char *s);
char	*ft_mess_error(int e);

int		ft_str_comp(char *s1, char s2);
int		ft_strlen(char *str)
int		check_map_first_lastline(char *str, char c);
int		check_inter_line(char *str, char c);
int		check_form_map(char *str, char *strnext);
int		check_map;

#endif
