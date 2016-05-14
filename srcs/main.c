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
}

static void		ft_print_map(t_a *a)
{
	int			y;
	int			x;

	y = -1;
	while (++y < (a->max_y))
	{
		x = -1;
		while (++x < (a->max_x))
		{
			ft_putchar(a->map[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

static int		wolf_exit(t_a *a)
{
	(void)a;
	ft_error("Good Buy My Friends ... Tchuss");
	return (0);
}

static void		mlx_expose(t_a *a)
{
	mlx_hook(a->win, 2, 1L << 2, wolf_keyboard, a);
	// mlx_hook(a.win, 6, 1L << 6, wolf_mouse, &a);
	mlx_hook(a->win, 17, 1L << 17, wolf_exit, a);
	mlx_mouse_hook(a->win, wolf_mouse, a);
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
	ft_print_map(&a);
	ft_localisation_start(&a);
	mlx_expose(&a);
	return (0);
}
