/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_hypotenuse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:56:14 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/24 13:56:16 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void			hypotenuse_other(t_a *a)
{
	if (a->p2x == a->p1x && a->p2y < a->p1y)
		WALL = (a->p1y - a->p2y);
	else if (a->p2x == a->p1x && a->p2y > a->p1y)
		WALL = (a->p2y - a->p1y);
	else if (a->p2x < a->p1x && a->p2y == a->p1y)
		WALL = (a->p1x - a->p2x);
	else if (a->p2x > a->p1x && a->p2y == a->p1y)
		WALL = (a->p2x - a->p1x);
}

static void			the_last_if(t_a *a, double i, int side_1, int side_2)
{
	int				s1;
	int				s2;

	s1 = pow(side_1, 2);
	s2 = pow(side_2, 2);
	WALL = (sqrt(s1 + s2));
	if (i < a->angle + 30)
		WALL = WALL * cos((PI * ((((a->angle + 30)) - i)) / 180));
	else if (i > a->angle + 30)
		WALL = WALL * cos((PI * ((i - (a->angle + 30))) / 180));
	else if (i == a->angle)
		WALL = WALL * cos((PI * (i)) / 180);
}

void				hypotenuse(t_a *a, double i)
{
	int		side_1;
	int		side_2;

	if ((a->p2x > a->p1x && a->p2y < a->p1y) ||
		(a->p2x > a->p1x && a->p2y > a->p1y))
	{
		side_1 = a->p2x - a->p1x;
		if (a->p2y > a->p1y)
			side_2 = a->p2y - a->p1y;
		else
			side_2 = a->p1y - a->p2y;
	}
	else if ((a->p2x < a->p1x && a->p2y < a->p1y) ||
		(a->p2x < a->p1x && a->p2y > a->p1y))
	{
		side_1 = a->p1x - a->p2x;
		if (a->p2y > a->p1y)
			side_2 = a->p2y - a->p1y;
		else
			side_2 = a->p1y - a->p2y;
	}
	else if (a->p2x == a->p1x || a->p2y == a->p1y)
		hypotenuse_other(a);
	if (a->p2x != a->p1x && a->p2y != a->p1y)
		the_last_if(a, i, side_1, side_2);
}
