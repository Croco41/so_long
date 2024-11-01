/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 15:27:31 by cgranja           #+#    #+#             */
/*   Updated: 2022/03/03 19:32:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_map(t_admin *admin, int fd, int y)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (ft_error_int(ft_mess_error(9), 9));
	admin->map.map[y++] = ft_strdup(line);
	free(line);
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (ft_error_int(ft_mess_error(9), 9));
		if (line[0] == '\0')
			return (ft_free_line(ret, line));
		admin->map.map[y] = ft_strdup(line);
		free(line);
		if (check_map(&admin->map, y) != 0)
			return (1);
		if (admin->map.map[y] == NULL)
			return (1);
		y++;
	}
	return (0);
}

int	ft_check_wall_map(t_admin *admin, int y)
{
	if (check_map_first_lastline(admin->map.map[y], '1') != 0)
		return (1);
	y++;
	while (y < admin->map.nbline - 1)
	{
		if (check_inter_line(admin->map.map[y], '1') != 0)
			return (1);
		y++;
	}
	if (check_map_first_lastline(admin->map.map[y], '1') != 0)
		return (1);
	return (0);
}

int	ft_opencheckfile(char *s)
{
	int	size;
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
		return (ft_error_int("Error during opening of fd", 0));
	close(fd);
	size = ft_strlen(s) - 1;
	if (size <= 3)
		return (ft_error_int(ft_mess_error(8), 8));
	if (ft_strncmp(s, ".ber", size) != 0)
		return (ft_error_int(ft_mess_error(7), 7));
	if (open(s, O_DIRECTORY) > 0)
		return (ft_error_int(ft_mess_error(6), 6));
	return (0);
}

int	main(int argc, char **argv)
{
	t_admin	admin;

	if (argc < 2)
		return (ft_error_int(ft_mess_error(1), 1));
	if (argc > 2)
		return (ft_error_int(ft_mess_error(2), 2));
	if (ft_opencheckfile(argv[1]))
		return (1);
	init_struct(&admin);
	ft_parse_map(&admin, argv[1]);
	if (!mlx_start_init(&admin.mlx, &admin, &admin.map))
	{
		return (1);
	}
	return (0);
}
