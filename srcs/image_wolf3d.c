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

void			ft_creat_windows_image(t_a *a)
{
	if (!(a->mlx = mlx_init()))
		ft_error("Probleme MLX INIT");
	a->str = "WOLF3D by Gautier Hubault      \"gahubaul\"";
	if (!(a->win = mlx_new_window(a->mlx, MAX_X, MAX_Y, a->str)))
		ft_error("Probleme MLX WIN");
	if (!(a->img1 = mlx_new_image(a->mlx, MAX_X, (MAX_Y / 2))))
		ft_error("Probleme MLX IMG");
	if (!(DATA1 = mlx_get_data_addr(a->img1, &a->bpp1, &a->sl1, &a->e)))
		ft_error("Probleme MLX DATA");
	a->bpp1 /= 8;
	if (!(a->img2 = mlx_new_image(a->mlx, MAX_X, (MAX_Y / 2))))
		ft_error("Probleme MLX IMG");
	if (!(DATA2 = mlx_get_data_addr(a->img2, &a->bpp2, &a->sl2, &a->e)))
		ft_error("Probleme MLX DATA");
	a->bpp2 /= 8;
}

void			ft_init_key(t_a *a)
{
	if (a->key_w == 1)
		wolf_keyboard_move(a, W);
	if (a->key_s == 1)
		wolf_keyboard_move(a, S);
	if (a->key_a == 1)
		wolf_keyboard_move(a, A);
	if (a->key_d == 1)
		wolf_keyboard_move(a, D);
	if (a->key_left == 1)
	{
		a->angle += 2;
		ft_putnbr_end(a->angle);
	}
	if (a->key_right == 1)
		a->angle += -2;
	if (a->key_shift == 1)
		a->speed = 1;
	if (a->key_shift == 0)
		a->speed = 3;
}

static void		event_key_press_next(int keycode, t_a *a)
{
	if (keycode == V)
		a->key_v *= -1;
	else if (keycode == SHIFT)
		a->key_shift = 1;
	else if (keycode == 89)
		a->key_p *= -1;
	else if (keycode == P && a->key_p != 1)
	{
		ft_putstr("\033[33;31m\nThe Segfault's Key Actived\n");
		a->map[a->max_y + 2][1] = '1';
	}
	else if (a->key_p != 1 && keycode != P)
		a->key_p *= -1;
	else if (keycode == P && a->key_p == 1)
		ft_print_map(a);
}

int				event_key_press(int keycode, t_a *a)
{
	if (keycode == 53)
		ft_error("Good Buy My Friends ... Tchuss");
	else if (keycode == W)
		a->key_w = 1;
	else if (keycode == S)
		a->key_s = 1;
	else if (keycode == A)
		a->key_a = 1;
	else if (keycode == D)
		a->key_d = 1;
	else if (keycode == LEFT)
		a->key_left = 1;
	else if (keycode == RIGHT)
		a->key_right = 1;
	else if (keycode == C)
		a->key_c *= -1;
	event_key_press_next(keycode, a);
	return (0);
}

int				event_key_release(int keycode, t_a *a)
{
	if (keycode == W)
		a->key_w = 0;
	else if (keycode == S)
		a->key_s = 0;
	else if (keycode == A)
		a->key_a = 0;
	else if (keycode == D)
		a->key_d = 0;
	else if (keycode == LEFT)
		a->key_left = 0;
	else if (keycode == RIGHT)
		a->key_right = 0;
	else if (keycode == SHIFT)
		a->key_shift = 0;
	return (0);
}
