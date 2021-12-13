/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:48:52 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/13 18:25:22 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->nbline)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	ft_free_all_mlx(t_mlx *mlx)
{
	if (mlx->collectible)
		mlx_destroy_image(mlx->mlx, mlx->collectible)
	if (mlx->player)
		mlx_destroy_image(mlx->mlx, mlx->player);
	if (mlx->ground)
		mlx_destroy_image(mlx->mlx, mlx->ground);
	if (mlx->wall)
		mlx_destroy_image(mlx->mlx, mlx->wall);
	if (mlx->exit)
		mlx_destroy_image(mlx->mlx, mlx->exit);
	if (mlx->window)
		mlx_destroy_image(mlx->mlx, mlx->window);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx)
		free(mlx->mlx);
	}
}
