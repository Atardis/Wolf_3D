/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line_angle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 17:29:26 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/19 17:29:28 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int		other(t_a *a, int x, int y)
{
	int			i;

	i = *(unsigned int *)(a->data2 + (x * a->bpp2) + (y * a->sl2));
	if (i != BLACK)
	{
		a->p2x = a->bx;
		a->p2y = a->by;
		return (-1);
	}
	return (1);
}

static void		ligne_if(t_a *a)
{
	int			cumul;
	int			stop;
	int			j;

	cumul = a->bdx / 2;
	a->bi = 0;
	stop = 1;
	j = 0;
	while (++a->bi <= a->bdx && stop == 1)
	{
		j++;
		a->bx += a->bxinc;
		cumul += a->bdy;
		if (cumul >= a->bdx)
		{
			cumul -= a->bdx;
			a->by += a->byinc;
		}
		stop = other(a, a->bx, a->by);
	}
}

static void		ligne_else(t_a *a)
{
	int			cumul;
	int			stop;
	int			j;

	cumul = a->bdy / 2;
	a->bi = 0;
	j = 0;
	stop = 1;
	while (++a->bi <= a->bdy && stop == 1)
	{
		j++;
		a->by += a->byinc;
		cumul += a->bdx;
		if (cumul >= a->bdy)
		{
			cumul -= a->bdy;
			a->bx += a->bxinc;
		}
		stop = other(a, a->bx, a->by);
	}
}

void			ligne_angle(t_a *a)
{
	a->bx = a->p1x;
	a->by = a->p1y;
	a->bdx = a->p2x - a->p1x;
	a->bdy = a->p2y - a->p1y;
	a->bxinc = (a->bdx > 0) ? 1 : -1;
	a->byinc = (a->bdy > 0) ? 1 : -1;
	a->bdx = abs(a->bdx);
	a->bdy = abs(a->bdy);
	if (a->bdx > a->bdy)
		ligne_if(a);
	else
		ligne_else(a);
}
