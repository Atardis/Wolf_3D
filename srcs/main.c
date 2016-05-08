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

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}


int			main(int argc, char **argv)
{
	t_a		a;

	if (argc == 1 || argc > 2)
		ft_error("Wolf3d Executable Needs A Map\nSorry My Friends ...");
	ft_creat_windows_image(&a);
	(void)argv[1];
	mlx_hook(a.win, 2, 1L << 2, wolf_keyboard, &a);
	mlx_loop(a.mlx);
	return (0);
}
