/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveplayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 13:17:47 by cgranja           #+#    #+#             */
/*   Updated: 2022/01/20 14:29:04 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_move(t_mlx *mlx, t_player *player)
{

}

int	ft_readkey(int keycode, t_mlx *mlx, t_player *player)
{
	if (keycode == 97)
		ft_move(player->x - 1, player->y);
	if (keycode == 100)
		ft_move(player->x + 1, player->y);
	if (keycode == 119)
		ft_move(player->x, player->y - 1);
	if (keycode == 115)
		ft_move(player->x, player->y + 1);
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
		free(mlx->mlx);
		return(0);
	}
	return (1);
}

int	ft_count_move(t_player *player)
{
	player->move = 0;
	printf(GREEN"Compteur de deplacement: \n");

}
