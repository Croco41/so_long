/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:33:07 by user42            #+#    #+#             */
/*   Updated: 2022/03/03 14:37:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    move_up(t_admin *admin, t_player *player, t_map *map, int fx, int fy)
{
        if (map->map[fy][fx] == '1')
                return ;
        if (map->map[fy][fx] == 'E')
        {
                if (map->nbcollecti == 0)
                        ft_closeok(admin);
                return ;
        }
        player->move++;
	ft_putnbr_fd(player->move, 1);
	write(1, "\r", 1);
        if (map->map[fy][fx] == 'C')
        {
                map->nbcollecti--;
                map->map[player->y][player->x] = '0';
		player->y = fy;
		player->x = fx;
		map->map[player->y][player->x] = 'P';
		//mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->player.img,
                  //      player->px, player->py);

        }
	//printf(" %d \n %d  \n", fx, fy);
	//printf(" %d \n %d  \n", player->x, player->y);
	if (map->map[fy][fx] != 'E')
        {
                map->map[player->y][player->x] = '0';
                player->y = fy;
		player->x = fx;
                map->map[player->y][player->x] = 'P';
        }
        return ;
}

