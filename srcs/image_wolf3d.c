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
	a->str = "WOLF3D by Gautier Hubault  gahubaul";
	if (!(a->win = mlx_new_window(a->mlx, 500, 500, a->str)))
		ft_error("Probleme MLX WIN");
}

int			wolf_keyboard(int keycode, t_a *a)
{
	(void)a;
	if (keycode == 53)
		ft_error("Good Buy My Friends ... Tchuss");
	return (0);
}
