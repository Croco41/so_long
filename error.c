/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:17:35 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/09 21:35:50 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_mess_error(int e)
{
	if (e == 1)
		return ("Error, too few arguments\n");
	if (e == 2)
		return ("Error, too much arguments\n");
	if (e==3)
		return("Error, character not allowd in map\n"); //fonction check_map
	return ("Error");
}


void	*ft_error(char *str, int e) //en char *str :fonctin ft_mess_error
{
	int i;

	i = -1;
	while (str[++i])
		write (2, &str[i], 1);
	return ;
}
	

