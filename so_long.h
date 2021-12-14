/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:29:34 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/14 17:28:44 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>

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
	t_mlx		mlx;
}				t_admin;


void	init_img(t_img *cimg);
void	init_mlx(t_mlx *cmlx);
void	init_map(t_map *map);
void	init_struct(t_admin *admin);
void	list_init(t_img *cimg, t_mlx *cmlx, t_map *cmap);



int		main(int argc, char **argv);
t_map	**ft_open_map(t_map **map, int fd);
int		ft_opencheckfile(char *s);

int		ft_create_map(t_admin *admin, char *s, int fd, int y);
int		ft_check_wall_map(t_admin *admin, char *s, int fd, int y);

char	*ft_mess_error(int e);
void	*ft_error(char *str, int e);
int		ft_error_int(char *str, int e);

int		ft_strncmp(char *s1, char s2, size_t n);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
int		get_next_line(int fd, char **line);
int		ft_strn(char *s);
char	*strjoin_gnl(char *s1, char *s2);



int		check_map_first_lastline(char *str, char c);
int		check_inter_line(char *str, char c);
int		ft_nbline_checkform(int fd, int y);
int		check_map(char *s, t_map **map, int l);

t_admin *ft_parse_map(t_admin *admin, char *argv);

void	ft_free_map(t_map *map);
void	ft_free_all_mlx(t_mlx *mlx);

#endif
