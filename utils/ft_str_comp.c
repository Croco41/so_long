/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 19:10:36 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/15 17:37:38 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*int	ft_str_comp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (s1 && s2)
	{
		while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
			i++;
	}
	return (s1[i] - s2[i]);
}*/

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned int i;
	int y;

	i = n - 3;
	y = 0;
	while (s1[i] != '\0' && s2[y] != '\0' && i < n)
	{
		if (s1[i] != s2[y])
			return (s1[i] - s2[y]);
		i++;
		y++;
	}
	if (((s1[i] == '\0' && s2[y] != '\0') ||
			(s2[y] == '\0' && s1[i] != '\0')) && i < n)
		return (s1[i] - s2[i]);
	return (0);
}



