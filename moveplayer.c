/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:17:47 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/03 15:25:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_readkey(int keycode, t_admin *admin)
{
	//printf("%d x: | %d y: \n", admin->player.x, admin->player.y);
	if (keycode == 97)
		move_up(admin, &admin->player, &admin->map, admin->player.x - 1, admin->player.y);
	if (keycode == 100)
		move_up(admin, &admin->player, &admin->map, admin->player.x + 1, admin->player.y);
	if (keycode == 119)
		move_up(admin, &admin->player, &admin->map, admin->player.x, admin->player.y - 1);
	if (keycode == 115)
		move_up(admin, &admin->player, &admin->map, admin->player.x, admin->player.y + 1);
	if (keycode == 65307)
	{
		ft_closeok(admin);
		return(0);
	}
	mlx_clear_window(admin->mlx.mlx, admin->mlx.mlx_win);
        print_img(&admin->mlx, &admin->map, &admin->player);
	return (1);
}

int	ft_count_move(t_admin *admin, t_player *player, t_mlx *mlx)
{
	player->move = 0;
	printf(GREEN"Compteur de deplacement: \n");
	mlx_key_hook(mlx->mlx_win, ft_readkey, admin);
//	if (player->move == 1523)
//		print_img(mlx, map, player);
	return (0);
}
