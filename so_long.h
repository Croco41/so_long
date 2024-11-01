/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:29:34 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/04 00:08:31 by user42           ###   ########.fr       */
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

# define BUFFER_SIZE 1024
# define PIX 64

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			*w;
	int			*h;
	int			bitspp;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	int			width;
	int			height;
	t_img		window;
	t_img		coll;
	t_img		player;
	t_img		ground;
	t_img		wall;
	t_img		exit;
}				t_mlx;

typedef struct s_player
{
	int			move;
	int			px;
	int			py;
	int			x;
	int			y;
}				t_player;

typedef struct s_map
{
	char		**map;
	int			nbcollecti;
	int			nbexit;
	int			nbplayer;
	int			sizeline;
	int			nbline;
	int			other;
	int			error;
	t_player	player;
}				t_map;

typedef struct s_admin
{
	t_map		map;
	t_mlx		mlx;
	t_player	player;
}				t_admin;

/*
***********************INITIALISATION**********************
*/
void	init_img(t_img *cimg);
void	init_mlx(t_mlx *cmlx);
void	init_map(t_map *map);
void	init_struct(t_admin *admin);
void	list_init(t_img *img, t_mlx *mlx);

int		main(int argc, char **argv);
//t_map		**ft_open_map(t_map **map, int fd);
int		ft_opencheckfile(char *s);

int		ft_create_map(t_admin *admin, int fd, int y);
int		ft_check_wall_map(t_admin *admin, int y);

/*
 * *********************ERROR********************************
*/

char	*ft_mess_error(int e);
char	*ft_mess_error_mlx(int e);
void	ft_error(char *str);
int		ft_error_int(char *str, int e);

/*
 * ********************UTILS*********************************
 */

int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
int		get_next_line(int fd, char **line);
int		ft_strn(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
void	ft_putnbr_fd(int n, int fd);

/*
 ***********************CHECK MAP******************************* 
 */

int		check_map_first_lastline(char *str, char c);
int		check_inter_line(char *str, char c);
int		ft_nbline_checkform(int fd, int y, int sizel, int error);
int		check_map(t_map *map, int l);

int		ft_parse_map(t_admin *admin, char *argv);
int		ft_parse_map_next(t_admin *admin);

/*
 *************************GRAPHICAL******************************
 */

int		mlx_start(t_mlx *mlx, t_admin *admin);
int		mlx_start_init(t_mlx *mlx, t_admin *admin, t_map *map);
int		load_img(t_mlx *mlx);
void	img_to_win(char c, t_admin *admin, int line, int x);
int		print_img(t_map *map, t_admin *admin);

void	move_up(t_admin *admin, t_map *map, int fx, int fy);
int		ft_readkey(int keycode, t_admin *admin);
int		ft_count_move(t_admin *admin, t_player *player, t_mlx *mlx);

/*
 * **************************FREE************************************
*/

int		ft_free_line(int ret, char *s);
void	ft_free_map(t_map *map);
void	ft_free_all_mlx(t_mlx *mlx);
int		ft_close(t_admin *admin);
int		ft_closeok(t_admin *admin);

#endif
