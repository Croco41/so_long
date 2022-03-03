/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:01:37 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/04 00:09:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_first_lastline(char *str, char c)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
	{
		return (1);
	}
	while (str && str[i])
	{
		if (str[i] != c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_inter_line(char *str, char c)
{
	int	len;

	len = ft_strlen(str);
	if (str[0] != c)
	{
		return (1);
	}
	if (str[len -1] != c)
	{
		return (1);
	}
	return (0);
}

int	ft_nbline_checkform(int fd, int y, int sizel, int error)
{
	char	*line;
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
		if ((ret == 1 && line[0] != '\0' && ft_strlen(line) != sizel)
			|| (line[0] == '\0' && ret == 1))
			error++;
		if (line[0] != '\0')
			y++;
		free(line);
	}
	if (error > 0)
		return (ft_error_int(ft_mess_error(10), 10));
	return (y);
}

int	check_map(t_map *map, int l)
{
	int		i;
	char	*s;

	s = map->map[l];
	i = -1;
	map->sizeline = ft_strlen(s);
	while (s[++i])
	{
		if (s[i] == 'P')
		{
			map->nbplayer++;
			map->player.x = i;
			map->player.y = l;
		}
		else if (s[i] == 'E')
			map->nbexit++;
		else if (s[i] == 'C')
			map->nbcollecti++;
		else if (s[i] == '1' || s[i] == '0')
			map->other++;
		else
			map->error++;
	}
	return (0);
}
