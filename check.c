/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:01:37 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/15 18:59:37 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_first_lastline(char *str, char c) // c = 1
{
	int	i;

	i = 0;
	while (*str)
	{
		if (str[i] != c)
			return (1);
		i++;
	}
	return (0);
}

int check_inter_line(char *str, char c) // a appeler pour chaque lignea verifier
{
	while (*str)
	{
		if (str[0] != c)
			return (1);
		if (str[ft_strlen(str)] != c)
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
		return (ft_error_int(ft_mess_error(5), 5));
	sizel = ft_strlen(line);
	free(line);
	y++;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (ft_error_int(ft_mess_error(5), 5));
		if ((line[0] != '\0' && ft_strlen(line) != sizel)
			|| (line[0] == '\0' && ret == 1))
			return (ft_error_int(ft_mess_error(10), 10));
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
			map->player.x = i;
			map->player.y = l;
			i++;
		}
		else if (s[i++] == 'E')
			map->nbexit++;
		else if (s[i++] == 'C')
			map->nbcollecti++;
		else if (s[i++] != '1' || s[i] != '0')
			return (ft_error_int(ft_mess_error(3), 3));
//		if (map->player != 1 || map->nbexit == 0 || map->nbcollecti == 0)
//			return (ft_error(ft_mess_error(4), 4));
	}
	
	return (0);
}
