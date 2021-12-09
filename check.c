/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:01:37 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/09 21:41:29 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_first_lastline(char *str, char c)
{
	int i;

	i = 0;
	while (*s)
	{
		if (s[i] != c)
			return (1);
		i++
	}
	return (0);
}

int	check_map(char *s, t_mao *map, int l)
{
	int i;

	i = -1;
	while (s[++i]
	{
		if (s[i] == 'P')
		{
			map->nbplayer++;
			map->player->x = i;
			map->player->y = l;
		}
		if (s[i] == 'E')
			map->nbexit++;
		if (s[i] == 'C')
			map->nbcollecti++;
		if (s[i] != '1' && s[i] != '0' && s[i] != 'P' && s[i] != 'E'
			& s[i] != 'C')
			return (ft_error(ft_mess_error(3), 3));
	}
	return (0);
}
