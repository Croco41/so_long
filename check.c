/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:01:37 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/13 17:44:52 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_first_lastline(char *str, char c) // c = 1
{
	int	i;

	i = 0;
	while (*s)
	{
		if (s[i] != c)
			return (1);
		i++
	}
	return (0);
}

int check_inter_line(char *str, char c)
{
	int	i;

	i = 0;

	while (*s)
	{
		if (s[0] != c)
			return (1);
		if (s[ft_strlen(str)] != c)
			return (1);
	}
	return (0);
}

int	ft_nbline_checkform(int fd, int y)
{
	char	*line;
	int		sizel;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (ft_error(ft_mess_error(5), 5));
	sizel = ft_strlen(line);
	free(line);
	y++;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (ft_error(ft_mess_error(5), 5));
		if ((line[0] != '\0' && ft_strlen(line) != sizel)
			|| (line[0] == '\0' && ret == 1))
			return (ft_error(ft_mess_error(10), 10));
		if (line[0] != '\0')
			y++;
		free(line);
	}
	return (y);
}

/*
int	check_form_map(char *str, char *strnext)
{
	int	size;
	int	i;

	size = ft_strlen(str);
	i = ft_strlen(strnext);
	if (size != i)
		return (1);
	return (0);
}*/

int	check_map(char *s, t_map *map, int l)
{
	int	i;

	i = -1;
	while (s[++i])
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
//		if (map->player != 1 || map->nbexit == 0 || map->nbcollecti == 0)
//			return (ft_error(ft_mess_error(4), 4));
	}
	
	return (0);
}
