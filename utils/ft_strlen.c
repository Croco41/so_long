/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:42:23 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/15 16:17:29 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_strlen(char *str)
{
	int	lenght;

	lenght = 0;
	if (!str)
		return (0);
	while (str[lenght])
		lenght++;
	return (lenght);
}
