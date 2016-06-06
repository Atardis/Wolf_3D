/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:12:49 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/11 17:12:59 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		print_alpha(t_a *a)
{
	a->p1x = a->x_start;
	a->p1y = a->y_start;
	a->p2x = a->x_start + (1000 * cos(a->angle * a->pi));
	a->p2y = a->y_start - (1000 * sin(a->angle * a->pi));
	ligne_angle(a);
	ligne(a, 0xFFFFFF, 2);
	a->p2x = a->x_start + (1000 * cos((a->angle + 60) * a->pi));
	a->p2y = a->y_start - (1000 * sin((a->angle + 60) * a->pi));
	ligne_angle(a);
	ligne(a, 0xFFFFFF, 2);
}

static void		print_start(t_a *a)
{
	int			y;
	int			x;
	int			c;

	c = 0xFFFFFF;
	x = a->x_start;
	y = a->y_start;
	if (x < MAX_X && x >= 0 && y >= 0 && y < (MAX_Y / 2))
		*(UI *)(DATA2 + ((x) * a->bpp2) + (y * a->sl2)) = c;
}

static void		ft_print_case(t_a *a, int y, int x)
{
	if ((MAX_Y2 / a->max_y) >= (MAX_X / a->max_x))
		a->size = (MAX_X / a->max_x);
	else if ((MAX_Y2 / a->max_y) < (MAX_X / a->max_x))
		a->size = (MAX_Y2 / a->max_y);
	else
		a->size = (MAX_Y2 / a->max_y);
	a->j = (a->size * y) - 1;
	while (++a->j < ((a->size * y) + a->size))
	{
		a->i = (a->size * x) - 1;
		while (++a->i < ((a->size * x) + a->size))
		{
			if (a->map[y][x] == '1' || a->map[y][x] == '2')
				a->color = (a->map[y][x] == '1') ? RED : BROWN;
			if (a->map[y][x] == '3' || a->map[y][x] == '4')
				a->color = (a->map[y][x] == '3') ? BLUEM : PINK;
			if (a->map[y][x] == '5' || a->map[y][x] == '.')
				a->color = (a->map[y][x] == '5') ? BLUE : BLACK;
			*(UI *)(DATA2 + (a->i * a->bpp2) + (a->j * a->sl2)) = a->color;
		}
	}
}

static void		ft_case(t_a *a)
{
	int			y;
	int			x;

	y = -1;
	while (++y < a->max_y)
	{
		x = -1;
		while (++x < a->max_x)
			ft_print_case(a, y, x);
	}
	y = -1;
	while (++y < MAX_X)
		ft_case_color(a, y);
	ft_print_wall_wolf(a);
	print_start(a);
	print_alpha(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img1, 0, 0);
	mlx_put_image_to_window(a->mlx, a->win, a->img2, 0, MAX_Y2);
}

int				print_skybox_and_ground(t_a *a)
{
	int		y;
	int		x;
	int		c;

	ft_init_key(a);
	y = -1;
	while (++y < MAX_Y / 2)
	{
		x = -1;
		while (++x < MAX_X)
		{
			c = (y < (MAX_Y / 4)) ? 0x55FEFE : 0xB4AF91;
			*(UI *)(DATA1 + (x * a->bpp1) + (y * a->sl1)) = c;
			if (y >= (MAX_X / 2) && x == MAX_X / 2 && a->key_v != 1)
				*(UI *)(DATA1 + (x * a->bpp1) + (y * a->sl1)) = RED;
			c = 0x000000;
			*(UI *)(DATA2 + (x * a->bpp2) + (y * a->sl2)) = c;
		}
	}
	ft_case(a);
	return (0);
}
