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

static void		ft_case(t_a *a)
{
	int			x;
	int			y;

	x = a->x_start;
	y = a->y_start;
	*(unsigned int *)(a->data + (x * a->bpp) + (y * a->sl)) = 0xFF0000;
}

void			print_skybox_and_ground(t_a *a)
{
	int		y;
	int		x;
	int		c;

	y = -1;
	while (++y < MAX_Y)
	{
		x = -1;
		while (++x < MAX_X)
		{
			c = (y < (MAX_Y / 2)) ? 0x759BE8 : 0x6CCE8C;
			*(unsigned int *)(a->data + (x * a->bpp) + (y * a->sl)) = c;
		}
	}
	ft_case(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	ft_bzero(a->data, MAX_X * MAX_Y);
}