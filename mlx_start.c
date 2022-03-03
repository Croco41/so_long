/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:51:17 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/03 22:47:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_to_win(char c, t_admin *admin, int line, int x)
{
	int	p;

	p = PIX;
	if (c == '0')
		mlx_put_image_to_window(admin->mlx.mlx, admin->mlx.mlx_win,
			admin->mlx.ground.img, x * p, line * p);
	if (c == '1')
		mlx_put_image_to_window(admin->mlx.mlx, admin->mlx.mlx_win,
			admin->mlx.wall.img, x * p, line * p);
	if (c == 'C')
		mlx_put_image_to_window(admin->mlx.mlx, admin->mlx.mlx_win,
			admin->mlx.coll.img, x * p, line * p);
	if (c == 'P')
	{
		admin->player.x = x;
		admin->player.y = line;
		mlx_put_image_to_window(admin->mlx.mlx, admin->mlx.mlx_win,
			admin->mlx.player.img, x * p, line * p);
	}
	if (c == 'E')
		mlx_put_image_to_window(admin->mlx.mlx,
			admin->mlx.mlx_win, admin->mlx.exit.img, x * p, line * p);
}

int	load_img(t_mlx *mlx)
{
	int	pix;

	pix = PIX;
	mlx->ground.img = mlx_xpm_file_to_image(mlx->mlx, "./text/0.xpm",
			&pix, &pix);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx, "./text/1.xpm",
			&pix, &pix);
	mlx->coll.img = mlx_xpm_file_to_image(mlx->mlx, "./text/C.xpm",
			&pix, &pix);
	mlx->player.img = mlx_xpm_file_to_image(mlx->mlx, "./text/P.xpm",
			&pix, &pix);
	mlx->exit.img = mlx_xpm_file_to_image(mlx->mlx, "./text/E.xpm",
			&pix, &pix);
	if (mlx->ground.img == NULL || mlx->wall.img == NULL
		|| mlx->coll.img == NULL || mlx->player.img == NULL
		|| mlx->exit.img == NULL)
	{
		ft_error_int(ft_mess_error_mlx(3), 3);
		return (1);
	}
	return (0);
}

int	print_img(t_map *map, t_admin *admin)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (y < map->nbline)
	{
		x = 0;
		while (x < map->sizeline)
		{
			img_to_win(map->map[y][x], admin, y, x);
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
		return (ft_error_int(ft_mess_error_mlx(1), 1));
	}
	if (load_img(mlx) == 1)
	{
		ft_close(admin);
		return (ft_error_int(ft_mess_error_mlx(1), 1));
	}
	mlx->width = PIX * admin->map.sizeline;
	mlx->height = PIX * (admin->map.nbline);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "so_long");
	if (!mlx->mlx_win)
	{
		ft_close(admin);
		return (ft_error_int(ft_mess_error_mlx(2), 2));
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
	if (print_img(map, admin) == 1)
	{
		ft_close(admin);
		return (1);
	}
	if (ft_count_move(admin, &admin->player, mlx) == 1)
		return (1);
	mlx_hook(mlx->mlx_win, 17, 1L << 17, ft_closeok, admin);
	mlx_loop(mlx->mlx);
	return (0);
}
