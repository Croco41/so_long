/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:17:47 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/03 03:02:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	move2(t_admin *admin, t_player *player, t_mlx *mlx, int to_y, int to_x)
{
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->ground.img,
                        player->x * 64, player->y * 64);

	admin->map.map[player->y][player->x] = '0';
	player->y = to_y;
        player->x = to_x;
	return ;
}

int ft_move(t_admin *admin, t_player *player, t_mlx *mlx, int to_y, int to_x)
{
	player->py = to_y * PIX;
	player->px = to_x * PIX;
	if (admin->map.map[to_y][to_x] == '1')
		return (1);
	player->move++;
	ft_putnbr_fd(player->move, 1);
	write(1, "\r", 1);
	if (admin->map.map[to_y][to_x] == 'E')
		if (admin->map.nbcollecti == 0)
			ft_closeok(admin);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player.img, 
			player->px, player->py);
	if (admin->map.map[to_y][to_x] == 'C')
		admin->map.nbcollecti--;
	else if (admin->map.map[player->y][player->x] == 'E')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->exit.img,
			player->x * 64, player->y * 64);
		player->y = to_y;
		player->x = to_x;
		printf(YELLOW"\n!! YOU WIN !!\n"CYAN"Mouv : %d", player->move);
		return (0);
	}
	move2(admin, player, mlx, to_y, to_x);
	return (0);
}
*/
int	ft_readkey(int keycode, t_admin *admin, t_player *player)
{
	printf("%d x: | %d y: \n", player->x, player->y);
	if (keycode == 97)
		ft_move(admin, player, &admin->mlx, player->x - 1, player->y);
	if (keycode == 100)
		ft_move(admin, player, &admin->mlx, player->x + 1, player->y);
	if (keycode == 119)
		ft_move(admin, player, &admin->mlx, player->x, player->y - 1);
	if (keycode == 115)
		ft_move(admin, player, &admin->mlx, player->x, player->y + 1);
	if (keycode == 65307)
	{
		ft_closeok(admin);
		return(0);
	}
	return (1);
}

int	ft_count_move(t_player *player, t_mlx *mlx)
{
	player->move = 0;
	printf(GREEN"Compteur de deplacement: \n");
	mlx_key_hook(mlx->mlx_win, ft_readkey, mlx);
	return (0);
}
