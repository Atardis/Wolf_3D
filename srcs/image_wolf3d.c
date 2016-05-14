/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 06:39:57 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/08 06:39:59 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_creat_windows_image(t_a *a)
{
	if (!(a->mlx = mlx_init()))
		ft_error("Probleme MLX INIT");
	a->str = "WOLF3D by Gautier Hubault      \"gahubaul\"";
	if (!(a->win = mlx_new_window(a->mlx, MAX_X, MAX_Y, a->str)))
		ft_error("Probleme MLX WIN");
	if (!(a->img = mlx_new_image(a->mlx, MAX_X, MAX_Y)))
		ft_error("Probleme MLX IMG");
	if (!(a->data = mlx_get_data_addr(a->img, &a->bpp, &a->sl, &a->e)))
		ft_error("Probleme MLX DATA");
	a->bpp /= 8;
}

int			wolf_keyboard(int keycode, t_a *a)
{
	ft_putnbr_end(keycode);
	if (keycode == 53)
		ft_error("Good Buy My Friends ... Tchuss");
	if ((keycode == W || keycode == S) && (ft_print_case(a) != 0))
		a->y_start = (keycode == W) ? (a->y_start--) : (a->y_start++);
	mlx_clear_window(a->mlx, a->win);
	print_skybox_and_ground(a);
	return (0);
}

int			wolf_mouse(int keycode, int x, int y, t_a *a)
{
	ft_putnbr_end(keycode);
	(void)a;
	ft_putstr("X -> ");
	ft_putnbr_end(x);
	ft_putstr("Y -> ");
	ft_putnbr_end(y);
	ft_putchar('\n');
	return (0);
}
