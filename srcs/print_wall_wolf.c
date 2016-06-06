/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wall_wolf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 13:26:23 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/19 13:27:25 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	ft_trace_wall_image(t_a *a, int col)
{
	int		y;
	double	yolo;
	double	tmp;
	double	size;

	yolo = (MAX_X / 2) / tan(PI * (30) / 180);
	size = (yolo * (a->size)) / a->dist_wall;
	if (size > MAX_X)
		size = MAX_X;
	y = ((MAX_X - size) / 2) - 1;
	tmp = size + (MAX_X - size) / 2;
	while (++y < tmp)
		if (col >= 0 && col <= MAX_X && y >= 0 && y < MAX_Y2)
			*(UI *)(a->data1 + (col * a->bpp1) + (y * a->sl1)) = a->color;
}

void		ft_print_wall_wolf(t_a *a)
{
	double	i;
	int		j;

	a->dist_wall = 1;
	a->p1x = a->x_start;
	a->p1y = a->y_start;
	i = a->angle;
	j = -1;
	while (i < (a->angle + 60) && ++j < MAX_X)
	{
		a->p1x = a->x_start;
		a->p1y = a->y_start;
		a->p2x = a->x_start + (1000 * cos(i * a->pi));
		a->p2y = a->y_start - (1000 * sin(i * a->pi));
		ligne_angle(a);
		if (a->key_c != 1)
			ft_check_color_position_side(a);
		else
			ft_check_color_position_case(a);
		hypotenuse(a, i);
		ft_trace_wall_image(a, ((MAX_X - 1) - j));
		i += 0.12;
	}
}
