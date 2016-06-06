/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 06:21:30 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/08 06:21:32 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		fonction_init(t_a *a)
{
	a->max_y = 0;
	a->max_x = 0;
	a->x_start = 250;
	a->y_start = 250;
	a->angle = 60.0;
	a->pi = (PI / 180.0);
	a->dist_wall = 1;
	a->key_c = 1;
	a->key_w = 0;
	a->key_s = 0;
	a->key_a = 0;
	a->key_d = 0;
	a->key_v = 1;
	a->key_p = 1;
	a->angle_cos = -1;
	a->safe = 1;
	a->key_shift = 0;
	a->key_left = 0;
	a->key_right = 0;
	a->key_r = 1;
	a->key_up = 0;
	a->key_down = 0;
}

void			ft_print_map(t_a *a)
{
	int			y;
	int			x;

	y = -1;
	ft_putstr("\033[33m\n");
	while (++y < (a->max_y))
	{
		x = -1;
		while (++x < (a->max_x))
		{
			ft_putchar(a->map[y][x]);
			ft_putstr(" ");
		}
		ft_putchar('\n');
	}
	ft_putstr("\n");
}

static int		wolf_exit(t_a *a)
{
	(void)a;
	ft_error("Good Buy My Friends ... Tchuss");
	return (0);
}

static void		mlx_expose(t_a *a)
{
	mlx_hook(a->win, 2, 1L << 0, event_key_press, a);
	mlx_hook(a->win, 3, 1L << 1, event_key_release, a);
	mlx_hook(a->win, 17, 1L << 17, wolf_exit, a);
	mlx_loop_hook(a->mlx, print_skybox_and_ground, a);
	mlx_loop(a->mlx);
}

int				main(int argc, char **argv)
{
	t_a		a;

	if (argc == 1 || argc > 3)
		ft_error("Wolf3d Executable Needs A Map\nSorry My Friends ...");
	fonction_init(&a);
	ft_open_map(&a, argv[1]);
	ft_creat_windows_image(&a);
	print_skybox_and_ground(&a);
	mlx_expose(&a);
	return (0);
}
