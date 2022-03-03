/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:51:17 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/03 02:52:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int put_texture_inwin(

void	img_to_win(char c, t_mlx *mlx, int line, int x, t_player *player)
{
	int p;

	p = PIX;
	
	if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, 
				mlx->ground.img, x * p, line * p);
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, 
				mlx->wall.img, x * p, line * p);
	if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, 
				mlx->coll.img, x * p, line * p);
	if (c == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, 
			mlx->player.img, x * p, line * p);
		player->x = x;
		player->y = line;
		printf("%d x2: | %d y2: \n", player->x, player->y);

	}
	if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, 
			mlx->mlx_win, mlx->exit.img, x * p, line * p);
}

int	load_img(t_mlx *mlx)
{
	int pix;

	pix = PIX;

	mlx->ground.img = mlx_xpm_file_to_image(mlx->mlx, "./text/0.xpm", &pix, &pix);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx, "./text/1.xpm", &pix, &pix);
	mlx->coll.img = mlx_xpm_file_to_image(mlx->mlx, "./text/C.xpm", &pix, 
	&pix);
	mlx->player.img = mlx_xpm_file_to_image(mlx->mlx, "./text/P.xpm", &pix, &pix);
	mlx->exit.img = mlx_xpm_file_to_image(mlx->mlx, "./text/E.xpm", &pix, &pix);
	if (mlx->ground.img == NULL || mlx->wall.img == NULL ||
	mlx->coll.img == NULL || mlx->player.img == NULL || mlx->exit.img == NULL)
	{
		ft_error_int(ft_mess_error_mlx(3), 3);
		return (1);
	}
	return (0);
}

int	print_img(t_mlx *mlx, t_map *map, t_player *player)
{
	int x;
	int y;

	y = 0;
	x = 0;
	//printf("%d \n", map->nbline);	
	while( y < map->nbline)
	{
		x = 0;
		while (x < map->sizeline)
		{
		//	printf("%c \n", map->map[y][x]);
			img_to_win(map->map[y][x] , mlx, y, x, player);
			x++;
		}
		y++;
	}
	return (0);
}


int	mlx_start(t_mlx *mlx, t_admin *admin)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		ft_close(admin);
		return(ft_error_int(ft_mess_error_mlx(1), 1));
		//ft_close(mlx, map);
	}
	if (load_img(mlx) == 1)
	{
		ft_close(admin);
		return(ft_error_int(ft_mess_error_mlx(1), 1));
		//ft_close(mlx, map);
	}
	mlx->width = PIX * admin->map.sizeline;
	mlx->height = PIX * (admin->map.nbline);
	//printf("%d \n", map->nbline);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "so_long");
	if (!mlx->mlx_win)
	{
		ft_close(admin);
		return(ft_error_int(ft_mess_error_mlx(2), 2));
		//ft_close(mlx, map);
	}
	return (0);
}

int	mlx_start_init(t_mlx *mlx, t_admin *admin, t_map *map)
{
	if (mlx_start(mlx, admin) == 1)
	{
		ft_close(admin);
		return (1);
	}
	if (print_img(mlx, map, &admin->player) == 1)
	{
		ft_close(admin);
		return(1);
	}
	if (ft_count_move(&admin->player, mlx) == 1)
		return (1);

//	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_hook, mlx);
	mlx_hook(mlx->mlx_win, 17, 1L << 17, ft_closeok, mlx);
//	mlx_hook(mlx->mlx_win, 15, 1L << 16, reset_window, admin);
	mlx_loop(mlx->mlx);
	return (0);
}
