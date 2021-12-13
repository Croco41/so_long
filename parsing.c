/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:43:08 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/13 18:36:29 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_admin	*ft_parse_map(t_admin *admin, char *argv)
{
	int	fd;
	int	i;

	i = 0;
	fd = open(argv, O_RDONLY);
	admin->map->nbline = ft_nbline_checkform(fd, 0);
	close(fd);
	if (admin->map->nbline == -1)
		return (NULL);
	admin->map->map = malloc(sizeof(admin->map->map) * admin->map->nbline);
	if (!admin->map->map)
		return (ft_error(ft_mess_error(11), 11));
	while (i < admin->map->nbline)
	{
		admin->map->map[i] = NULL;
		i++;
	}
	fd = open(orgv, O_RDONLY);
	admin->map->map = ft_create_map(admin, argv, fd, 0);
	close (fd);
	if (admin->map->map == NULL)
		return (NULL);
	if (ft_check_wall_map(admin, argv, fd, 0) > 0)
		return (f

	return (admin);
}
