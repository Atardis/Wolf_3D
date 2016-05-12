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
	(void)a;
	if (keycode == 53)
		ft_error("Good Buy My Friends ... Tchuss");
	if ((keycode == W || keycode == S) && a->dist_wall <= 375)
	{
		a->dist_wall += (keycode == W) ? 15 : -15;
		a->dist_wall += (a->dist_wall == 0) ? 15 : 0;
		if (a->dist_wall > 375)
			a->dist_wall = 375;
	}
	mlx_clear_window(a->mlx, a->win);
	print_skybox_and_ground(a);
	return (0);
}

void		print_skybox_and_ground(t_a *a)
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
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
	ft_bzero(a->data, MAX_X * MAX_Y);
}