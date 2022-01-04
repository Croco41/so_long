/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:51:17 by cgranja           #+#    #+#             */
/*   Updated: 2022/01/04 17:44:13 by cgranja          ###   ########.fr       */
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
		mlx_put_image_to_window(mlx, mlx_win, mlx->ground, 0, 0);
	if (c == '1')
		mlx_put_image_to_window(mlx, mlx_win, mlx->wall, 0, 0);
	if (c == 'C')
		mlx_put_image_to_window(mlx, mlx_win, mlx->collectible, 0, 0);
	if (c == 'P')
		mlx_put_image_to_window(mlx, mlx_win, mlx->player, 0, 0);
	if (c == 'E')
		mlx_put_image_to_window(mlx, mlx_win, mlx->exit, 0, 0);

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
	mlx->ground = mlx_xpm_file_to_image(mlx , img_0, &ground->w, &ground->h);
	mlx->wall = mlx_xpm_file_to_image(mlx, img_1, &wall->w, &wall->h);
	mlx->collectible = mlx_xpm_file_to_image(mlx, img_C, &collectible->w,
	&collectible->h);
	mlx->player = mlx_xpm_file_to_image(mlx, img_P, &player->w, &player->h);
	mlx->exit = mlx_xpm_file_to_image(mlx, img_E, &exit->w, &exit->h);
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

