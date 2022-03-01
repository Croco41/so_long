/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:51:17 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/01 23:37:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//int put_texture_inwin(


static void	ft_close(int keycode, t_mlx *mlx)
{
//	if (keycode == 65307)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		free(mlx->mlx);
}

void	img_to_win(char c, t_mlx *mlx, int line, int x)
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
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, 
				mlx->player.img, x * p,  (line - 1) * p;
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
	if (mlx->ground == NULL || mlx->wall == NULL ||
	mlx->coll.img == NULL || mlx->player.img == NULL || mlx->exit.img == NULL)
	{
		ft_error_int(ft_mess_error_mlx(3), 3);
		return (1);
	}
	return (0);
}


int	mlx_start(t_mlx *mlx, t_admin *admin)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
	{
		ft_error_int(ft_mess_error_mlx(1), 1);
		ft_free_all_mlx(mlx);
		return (1);
	}
	mlx->width = PIX * admin->map.sizeline;
	mlx->height = PIX * admin->map.nbline;
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->width, mlx->height, "so_long");
	if (!mlx->mlx_win)
	{
		ft_error_int(ft_mess_error_mlx(2), 2);
		ft_free_all_mlx(mlx);
		return (1);
	}
	mlx_hook(mlx->mlx_win, 2, 1L<<0, ft_close, mlx);
	mlx_hook(mlx->mlx_win, 17, 1L<<17, ft_close, mlx);
//	put
	mlx_loop(mlx->mlx);
	return (0);
}

