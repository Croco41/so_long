/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:27:31 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/14 17:25:52 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*t_map		**ft_open_map(t_map **map, int fd)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (ft_error(ft_mess_error(5), 5);
	while (ret > 0)
	{
		






	}
	close(fd);
	free(line);
	return (0);
}*/

int	ft_create_map(t_admin *admin, char *s, int fd, int y)
{
	char	*line;
	int		ret;

//	init_map(&map);
	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (ft_error_int(ft_mess_error(9), 9));
	if (check_map(s, admin(&map), y) != 0)
		return (1);
	y++;
	while (ret == 1)
	{
		if (check_map(s, map, y) != 0)
			return (1);
		admin->map.map[y] = ft_strdup(line);
		free(line);
		if (admin->map.map  == NULL)
			return(1);
		ret = get_next_line(fd, &line);
		y++;
	}
	free(line);
	if (map->player != 1 || map->nbexit == 0 || map->nbcollecti == 0)
		return (ft_error_int(ft_mess_error(4), 4));
	return (0);
}

int	ft_check_wall_map(t_admin *admin, char *s, int fd, int y)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (ft_error_int(ft_mess_error(9), 9));
	if (check_map_first_lastline(line, '1') != 0)
		return (1);
	admin->map.map[y] = ft_strdup(line);
	free(line);
	y++;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		admin->map.map[y] = ft_strdup(line);
		if (check_inter_line(admin->map.map, y) != 0)
			return (1);
		free(line);
//		if (admin->map->map  == NULL)
//			return(//faire ft_free_line(ret, line, admin));
		y++;
	}
	if (check_map_first_lastline(admin->map.map[--y], '1') != 0)
		return (1);
	return (0);
}

int	ft_opencheckfile(char *s)
{
	int	i;
	int size;

	size = ft_strlen(s);
	i = 0;
	if (open(s, O_DIRECTORY) > 0)
		return (ft_error_int(ft_mess_error(6), 6));
	if (size <= 4)
		return (ft_error_int(ft_mess_error(8), 8));
	if (ft_strncmp(s, ".ber", size) != 0)
		return (ft_error_int(ft_mess_error(7), 7));
	return (0);
}

int	main(int argc, char **argv)
{
	t_admin *admin;

	admin = NULL;
	if (argc < 2)
		return (ft_error_int(ft_mess_error(1), 1));
	if (argc > 2)
		printf (ft_error(ft_mess_error(2), 2));
	if (ft_opencheckfile(argv[1]) != 0)
		return (1);
	init_struct(&admin);
	admin = ft_parse_map(admin, argv[1]);
	if (admin == NULL)
		return (1);
	ft_free_map(&admin->map);
	return (0);
}
//parse map
//start mlx(&all.mlx ,&all)

//appel de la fnction parsing
//attention cas null
//prevoir les free
