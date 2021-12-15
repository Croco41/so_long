/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:27:52 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/15 17:50:30 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_img *cimg)
{
	cimg->img = NULL;
	cimg->addr = NULL;
	cimg->img_width = 0;
	cimg->img_height = 0;
	cimg->bitspp = 0;
	cimg->line_length = 0;
	cimg->endian = 0;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->mlx_win = NULL;
	init_img(&mlx->window);
	init_img(&mlx->collectible);
	init_img(&mlx->player);
	init_img(&mlx->ground);
	init_img(&mlx->wall);
	init_img(&mlx->exit);
}

void	init_map(t_map *map)
{
	map->nbcollecti = 0;
	map->nbexit = 0;
	map->nbplayer = 0;
	map->nbline = 0;
}

void	init_struct(t_admin *admin)
{
	admin->map.map = NULL;
	admin->map.nbline = 0;
	admin->map.player.move = 0;
	admin->map.player.x = 0;
	admin->map.player.y = 0;
	init_mlx(&admin->mlx);
}

void	list_init(t_img *cimg, t_mlx *mlx)
{
	init_img(cimg);
	init_mlx(mlx);
//	init_map(map);
}
