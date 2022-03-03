/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:48:52 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/03 22:42:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_line(int ret, char *line)
{
	int	i;

	i = 0;
	if (ret == -1)
		return (0);
	free(line);
	return (0);
}

void	ft_free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->map)
	{
		while (i < map->nbline)
		{
			if (map->map[i])
			{
				free(map->map[i]);
				i++;
			}
		}
		free(map->map);
	}
}

void	ft_free_all_mlx(t_mlx *mlx)
{
	if (mlx->coll.img)
		mlx_destroy_image(mlx->mlx, mlx->coll.img);
	if (mlx->player.img)
		mlx_destroy_image(mlx->mlx, mlx->player.img);
	if (mlx->ground.img)
		mlx_destroy_image(mlx->mlx, mlx->ground.img);
	if (mlx->wall.img)
		mlx_destroy_image(mlx->mlx, mlx->wall.img);
	if (mlx->exit.img)
		mlx_destroy_image(mlx->mlx, mlx->exit.img);
	if (mlx->window.img)
		mlx_destroy_image(mlx->mlx, mlx->window.img);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->mlx)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
}

int	ft_close(t_admin *admin)
{
	if (admin->mlx.mlx)
		ft_free_all_mlx(&admin->mlx);
	if (admin->map.map)
		ft_free_map(&admin->map);
	return (1);
}

int	ft_closeok(t_admin *admin)
{
	ft_close(admin);
	exit(0);
	return (0);
}
