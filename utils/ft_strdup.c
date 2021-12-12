/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:45:49 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/12 16:50:10 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *s)
{
	char	*result;
	size_t	i;
	size_t	src;

	src = ft_strlen(str);
	i = 0;
	if (s == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * src + 1);
	if (!result)
		return (0);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
