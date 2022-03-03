/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:43:08 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/03 01:28:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_parse_map(t_admin *admin, char *argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	admin->map.nbline = ft_nbline_checkform(fd, 0);
	close(fd);
	if (admin->map.nbline == -1)
		return (1);
	admin->map.map = malloc(sizeof(admin->map.map) * admin->map.nbline);
	if (!admin->map.map)
		return (ft_error_int(ft_mess_error(11), 11));
	while (i < admin->map.nbline)
	{
		admin->map.map[i] = NULL;
		i++;
	}
	fd = open(argv, O_RDONLY);
	ft_create_map(admin, fd, 0);
	close(fd);
	if (admin->map.map == NULL)
		return (1);
	if (ft_check_wall_map(admin, 0) > 0)
	{
		ft_free_map(&admin->map);
		return (1);
	}
	return (0);
}
