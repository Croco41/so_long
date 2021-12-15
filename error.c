/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:17:35 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/15 14:07:22 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_mess_error(int e)
{
	if (e == 1)
		return ("Error, too few arguments\n");
	if (e == 2)
		return ("Error, too much arguments\n");
	if (e == 3)
		return("Error, character not allowed in map\n");
	if (e == 4)
		return("Error, we need only on player and at least one exit and one collectible in map\n");
	if (e == 5)
		return("Return of -1 of GNL\n");
	if (e == 6)
		return("Error, File is a directory\n");
	if (e == 7)
		return("Error, bad Extension file\n");
	if (e == 8)
		return("Error, invalid name\n");
	if (e == 9)
		return ("Error, Return of -1 of GNL create map\n");
	if (e == 10)
		return ("Error, map is not rectangular\n");
	if (e == 11)
		return ("Error, Crash of Malloc\n");
		//fonction check_map
	return ("Error");
}


void	*ft_error(char *str, void *e) //en char *str :fonctin ft_mess_error
{
	int i;

	i = -1;
	while (str[++i])
		write (2, &str[i], 1);
	return (e);
}

int	ft_error_int(char *str, int e)
{
	int i;

	i = -1;
	while (str[++i])
		write (2, &str[i], 1);
	return (e);
}

