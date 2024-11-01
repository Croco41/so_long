/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:45:49 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/14 17:06:59 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strdup(char *str)
{
	char	*result;
	size_t	i;
	size_t	sizestr;

	sizestr = ft_strlen(str);
	i = 0;
	if (str == NULL)
		return (NULL);
	result = (char *)malloc(sizeof(char) * sizestr + 1);
	if (!result)
		return (0);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
