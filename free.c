/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:48:52 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/03 14:49:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_line(int ret, char *line)
{
	int i;

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
		//printf("%d   | %s \n ", i, map->map[i]);
		if (map->map[i])
		{
			free(map->map[i]);
			i++;
		}
	}
	free(map->map);
	}

	///printf("%d \n", map->nbline);
	//printf("%d \n", map->sizeline);
/*	if (map->map)
	{
		while (map->map[++i] && i < map->nbline)
			if (map->map[i])
				free(map->map[i]);
		//if (map->map[i])
		//	free(map->map[i]);
		free (map->map);
	}
	return ;*/
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

int     ft_close(t_admin *admin)
{
//	if (map)
  //              ft_free_map(map);

	if (admin->mlx.mlx)
                ft_free_all_mlx(&admin->mlx);
//	printf("%s \n ",  admin->map.map[0]);
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

