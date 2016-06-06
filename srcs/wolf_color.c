/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 13:57:20 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/24 13:57:24 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_check_color_position_side(t_a *a)
{
	if (*(UI *)(DATA2 + ((P2X - 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK)
		a->color = GREEN;
	if (*(UI *)(DATA2 + ((P2X + 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK)
		a->color = BLUE;
	if (*(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y - 1) * a->sl2)) == BLACK)
		a->color = YELLOW;
	if (*(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y + 1) * a->sl2)) == BLACK)
		a->color = PINK;
	if (*(UI *)(DATA2 + ((P2X - 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK
		&& *(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y - 1) * a->sl2)) == BLACK)
		a->color = BLACK;
	if (*(UI *)(DATA2 + ((P2X + 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK
		&& *(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y - 1) * a->sl2)) == BLACK)
		a->color = BLACK;
	if (*(UI *)(DATA2 + ((P2X - 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK
		&& *(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y + 1) * a->sl2)) == BLACK)
		a->color = BLACK;
	if (*(UI *)(DATA2 + ((P2X + 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK
		&& *(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y + 1) * a->sl2)) == BLACK)
		a->color = BLACK;
}

void		ft_check_color_position_case(t_a *a)
{
	if (*(UI *)(DATA2 + ((P2X - 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK
		&& *(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y - 1) * a->sl2)) == BLACK)
		a->color = BLACK;
	else if (*(UI *)(DATA2 + ((P2X + 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK
		&& *(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y - 1) * a->sl2)) == BLACK)
		a->color = BLACK;
	else if (*(UI *)(DATA2 + ((P2X - 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK
		&& *(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y + 1) * a->sl2)) == BLACK)
		a->color = BLACK;
	else if (*(UI *)(DATA2 + ((P2X + 1) * a->bpp2) + ((P2Y) * a->sl2)) == BLACK
		&& *(UI *)(DATA2 + ((P2X) * a->bpp2) + ((P2Y + 1) * a->sl2)) == BLACK)
		a->color = BLACK;
	else
		a->color = *(UI *)(DATA2 + (P2X * a->bpp2) + (P2Y * a->sl2));
}

void		ft_case_color(t_a *a, int y)
{
	if (a->key_c == 1)
	{
		*(UI *)(DATA2 + (0 * a->bpp2) + (y * a->sl2)) = WHITE;
		*(UI *)(DATA2 + ((MAX_X - 1) * a->bpp2) + (y * a->sl2)) = WHITE;
		*(UI *)(DATA2 + (y * a->bpp2) + (0 * a->sl2)) = WHITE;
		*(UI *)(DATA2 + (y * a->bpp2) + ((MAX_X - 1) * a->sl2)) = WHITE;
	}
	else if (a->key_c == -1)
	{
		*(UI *)(DATA2 + (0 * a->bpp2) + (y * a->sl2)) = BLUE;
		*(UI *)(DATA2 + (1 * a->bpp2) + (y * a->sl2)) = BLUE;
		*(UI *)(DATA2 + ((MAX_X - 1) * a->bpp2) + (y * a->sl2)) = GREEN;
		*(UI *)(DATA2 + ((MAX_X - 2) * a->bpp2) + (y * a->sl2)) = GREEN;
		*(UI *)(DATA2 + (y * a->bpp2) + (0 * a->sl2)) = PINK;
		*(UI *)(DATA2 + (y * a->bpp2) + (1 * a->sl2)) = PINK;
		*(UI *)(DATA2 + (y * a->bpp2) + ((MAX_X - 1) * a->sl2)) = RED;
		*(UI *)(DATA2 + (y * a->bpp2) + ((MAX_X - 2) * a->sl2)) = RED;
	}
}
