/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_wolf3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 06:39:57 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/08 06:39:59 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int		verif_move_vert(int keycode, t_a *a)
{
	int			x;
	int			y;
	int			i;

	if (keycode == W)
	{
		x = a->x_start + ((a->speed + 2) * cos((a->angle + 30) * a->pi));
		y = a->y_start - ((a->speed + 2) * sin((a->angle + 30) * a->pi));
	}
	if (keycode == S)
	{
		x = a->x_start + ((a->speed + 2) * cos((a->angle + 210) * a->pi));
		y = a->y_start - ((a->speed + 2) * sin((a->angle + 210) * a->pi));
	}
	i = *(UI *)(DATA2 + ((int)x * a->bpp2) + ((int)y * a->sl2));
	if (i != BLACK || x < 0 || x > MAX_X || y < 0 || y > MAX_X)
		return (0);
	return (1);
}

static int		verif_move_hor(int keycode, t_a *a)
{
	double		x;
	double		y;
	int			i;

	if (keycode == A)
	{
		x = a->x_start + ((a->speed + 2) * cos((a->angle + 120) * a->pi));
		y = a->y_start - ((a->speed + 2) * sin((a->angle + 120) * a->pi));
	}
	if (keycode == D)
	{
		x = a->x_start + ((a->speed + 2) * cos((a->angle + -60) * a->pi));
		y = a->y_start - ((a->speed + 2) * sin((a->angle + -60) * a->pi));
	}
	i = *(UI *)(DATA2 + ((int)x * a->bpp2) + ((int)y * a->sl2));
	if (i != BLACK || x < 0 || x > MAX_X || y < 0 || y > MAX_X)
		return (0);
	return (1);
}

void			wolf_keyboard_move(t_a *a, int keycode)
{
	if (keycode == W && verif_move_vert(W, a) == 1)
	{
		a->x_start = a->x_start + (a->speed * cos((a->angle + 30) * a->pi));
		a->y_start = a->y_start - (a->speed * sin((a->angle + 30) * a->pi));
	}
	if (keycode == S && verif_move_vert(S, a) == 1)
	{
		a->x_start = a->x_start + (a->speed * cos((a->angle + 210) * a->pi));
		a->y_start = a->y_start - (a->speed * sin((a->angle + 210) * a->pi));
	}
	else if (keycode == A && verif_move_hor(A, a) == 1)
	{
		a->x_start = a->x_start + (a->speed * cos((a->angle + 120) * a->pi));
		a->y_start = a->y_start - (a->speed * sin((a->angle + 120) * a->pi));
	}
	else if (keycode == D && verif_move_hor(D, a) == 1)
	{
		a->x_start = a->x_start + (a->speed * cos((a->angle + -60) * a->pi));
		a->y_start = a->y_start - (a->speed * sin((a->angle + -60) * a->pi));
	}
}
