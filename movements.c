/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:33:07 by user42            #+#    #+#             */
/*   Updated: 2022/03/04 12:25:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_admin *admin, t_map *map, int fx, int fy)
{
	if (map->map[fy][fx] == '1')
		return ;
	if (map->map[fy][fx] == 'E')
	{
		if (map->nbcollecti == 0)
		{
			printf(YELLOW"\n!!YOU WIN!!\n"CYAN"Mouvs: %d\n"RESET"\n",
				admin->player.move);
			ft_closeok(admin);
		}
		return ;
	}
	admin->player.move++;
	ft_putnbr_fd(admin->player.move, 1);
	write(1, "\r", 1);
	if (map->map[fy][fx] == 'C')
		map->nbcollecti--;
	if (map->map[fy][fx] == 'C' || map->map[fy][fx] != 'E')
	{
		map->map[admin->player.y][admin->player.x] = '0';
		admin->player.y = fy;
		admin->player.x = fx;
		map->map[admin->player.y][admin->player.x] = 'P';
	}
	return ;
}
