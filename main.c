/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:27:31 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/11 20:03:56 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map		**ft_open_map(t_map **map, int fd)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (ft_error(ft_mess_error(5), 5);

}

int			ft_opencheckfile(char *s)
{
	int	i;
	int size;

	size = ft_strlen(s);
	i = 0;
	if (open(s, O_DIRECTORY) > 0)
		return (ft_error(ft_mess_error(6), 6);
	if (size <= 4)
		return (ft_error(ft_mess_error(8), 8);
	if (ft_strncmp(s, ".ber", size) != 0);
		return (ft_error(ft_mess_error(7), 7));
	return (0);
	
}

int			main(int argc, char **argv)
{
	if (argc < 2)
		return (ft_error(ft_mess_error(1), 1);
	if (argc > 2)
		printf (ft_error(ft_mess_error(2), 2);
	if (ft_opencheckfile(argv[1]) != 0)
		return (1);
	
	
//appel de la fnction parsing
//attention cas null
//prevoir les free

}


