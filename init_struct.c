/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:27:52 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/14 16:53:57 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_img *cimg)
{
	cimg->img = NULL;
	cimg->addr = NULL;
	cimg->width = 0;
	cimg->height = 0;
	cimg->bitspp = 0;
	cimg->line_lenght = 0;
	cimg->endian = 0;
}

void	init_mlx(t_mlx *cmlx)
{
	cmlx->mlx = NULL;
	cmlx->mlx_win = NULL;
	init_img(&mlx->window);
	init_img(&mlx->collectible);
	init_map(&mlx->player);
	init_img(&mlx->ground);
	init_img(&mlx->wall);
	init_img(&mlx->exit);
}

void	init_map(t_map *map)
{
	cmap->nbcollecti = 0;
	cmap->nbexit = 0;
	cmap->nbplayer = 0;
	cmap->nbline = 0;
}

void	init_struct(t_admin *admin)
{
	admin->map.map = NULL;
	admin->map.nbline = 0;
	admin->map.player->move = 0;
	admin->map.player.x = 0;
	admin->map.player.y = 0;
	init_mlx(&admin->mlx);
}

void	list_init(t_img *cimg, t_mlx *cmlx, t_map *cmap)
{
	init_img(cimg);
	init_mlx(cmlx);
	init_map(cmap);
}
