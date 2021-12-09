/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgranja <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:34:13 by cgranja           #+#    #+#             */
/*   Updated: 2021/12/09 14:58:42 by cgranja          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <mlx.h>
//#include "minilibx-linux/mlx.h"
//#include "minilibx-linux/mlx_int.h"
#include <stdlib.h>
#include <stdio.h>


/*
typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x;
	int y;
	int color;
	char	*relative_path = "./bricks.xpm";
	int		img_width;
	int		img_height;	
	void	*img2;

	x = 100;
	y = 100;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	img2 = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

	while (x <= 400 && y <= 200)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		if (x == 400)
		{
			while (y <= 200)
			{
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
				y++;
			}
		}
	}
	while (x >= 100 && y >= 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x--;
		if (x == 100)
		{
			while (y >= 100)
			{
				my_mlx_pixel_put(&img, x, y, 0x00FF00);
				y--;
			}
		}
	}
	color = 0;

	x = 0;
	y = 10;
	while (x < 1900)
	{
		my_mlx_pixel_put(&img, x, y, 100 * x);
		x++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	x = 0;
	y = 15;
	while (x <= 1920 && y <= 1080)
	{
		x = 0;
		while (x <= 1920)
		{
			mlx_put_image_to_window(mlx, mlx_win, img2, x, y);
			x += 64;
		}
	}

//	mlx_put_image_to_window(mlx, mlx_win, img2, 0, 0);

//	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);

	mlx_loop(mlx);

	}
*/

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

/*int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	printf("%d\n", keycode);
}*/

/*int mouse_hook(int button, int x, int y, t_vars *vars)
{
	printf("%d, %d\n", x ,y);
}*/

int	close(int keycode, t_vars *vars)
{
//	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars->mlx);
}

//int resize(


int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 580, "Hello world!");
//	mlx_key_hook(vars.win, key_hook, &vars);
//	mlx_mouse_hook (vars.win, mouse_hook, &vars);
//	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
//	mlx_hook(vars.win, 25, 1L<<18, resize, &vars);
	mlx_hook(vars.win, 17, 1L<<17, close, &vars);

	mlx_loop(vars.mlx);
}
