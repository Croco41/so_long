/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:51:17 by cgranja           #+#    #+#             */
/*   Updated: 2022/01/06 15:09:50 by cgranja          ###   ########.fr       */
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

void	img_to_win(char c, t_mlx *mlx, t_admin *admin)
{
	if (c == '0')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ground.img, 0, 0);
	if (c == '1')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->wall.img, 0, 0);
	if (c == 'C')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->collectible.img, 0, 0);
	if (c == 'P')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player.img, 0, 0);
	if (c == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->exit.img, 0, 0);

}
/*
int	load_img(t_mlx *mlx)
{
	char	*img_0;
	char	*img_1;
	char	*img_C;
	char	*img_P;
	char	*img_E;

	img_0 = ".img/img_0.xpm";
	img_1 = ".img/img_1.xpm";
	img_C = ".img/img_C.xpm";
	img_P = ".img/img_P.xpm";
	img_E = ".img/img_E.xpm";
	mlx->ground = mlx_xpm_file_to_image(mlx->mlx, img_0, &mlx->ground.w, &mlx->ground.h);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, img_1, &mlx->wall.w, &mlx->wall.h);
	mlx->collectible = mlx_xpm_file_to_image(mlx->mlx, img_C, &mlx->collectible.w,
	&mlx->collectible.h);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, img_P, &mlx->player.w, &mlx->player.h);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, img_E, &mlx->exit.w, &mlx->exit.h);
	if (mlx->ground == NULL || mlx->wall == NULL ||
	mlx->collectible == NULL || mlx->player == NULL || mlx->exit == NULL)
	{
		ft_error_int(ft_mess_error_mlx(3), 3);
		return (1);
	}
	return (0);
}*/

int	load_img(t_mlx *mlx)
{
	int pix;

	pix = PIX;

	mlx->ground = mlx_xpm_file_to_image(mlx->mlx, ".img/img_0.xpm", &pix, &pix);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, ".img/img_1.xpm", &pix, &pix);
	mlx->collectible = mlx_xpm_file_to_image(mlx->mlx, ".img/img_C.xpm", &pix, 
	&pix);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx, ".img/img_P.xpm", &pix, &pix);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, ".img/img_E.xpm", &pix, &pix);
	if (mlx->ground == NULL || mlx->wall == NULL ||
	mlx->collectible == NULL || mlx->player == NULL || mlx->exit == NULL)
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

