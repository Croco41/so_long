/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:27:52 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/12 14:07:57 by cgranja          ###   ########.fr       */
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
}

void	init_map(t_map *cmap)
{
	cmap->nbcollecti = 0;
	cmap->nbexit = 0;
	cmap->nbplayer = 0;
	cmap->nbline = 0;
}

void	list_init(t_img *cimg, t_mlx *cmlx, t_map *cmap)
{
	init_img(cimg);
	init(cmlx);
	init(cmap);
}
