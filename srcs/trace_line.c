/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 14:31:11 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/12 14:31:14 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		ligne_if(t_a *a, int c)
{
	int			cumul;

	cumul = a->bdx / 2;
	a->bi = 0;
	while (++a->bi <= a->bdx)
	{
		a->bx += a->bxinc;
		cumul += a->bdy;
		if (cumul >= a->bdx)
		{
			cumul -= a->bdx;
			a->by += a->byinc;
		}
		*(unsigned int *)(a->data + (a->bx * a->bpp) + (a->by * a->sl)) = c;
	}
}

static void		ligne_else(t_a *a, int c)
{
	int			cumul;

	cumul = a->bdy / 2;
	a->bi = 0;
	while (++a->bi <= a->bdy)
	{
		a->by += a->byinc;
		cumul += a->bdx;
		if (cumul >= a->bdy)
		{
			cumul -= a->bdy;
			a->bx += a->bxinc;
		}
		*(unsigned int *)(a->data + (a->bx * a->bpp) + (a->by * a->sl)) = c;
	}
}

void			ligne(t_a *a, int c)
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
		ligne_if(a, c);
	else
		ligne_else(a, c);
}
