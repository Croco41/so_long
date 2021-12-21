/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:51:17 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/21 16:23:14 by cgranja          ###   ########.fr       */
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

