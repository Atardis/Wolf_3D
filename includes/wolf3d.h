/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 06:22:05 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/08 06:22:07 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLFF3D_H
# define WOLFF3D_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <mlx.h>

# define ESC 53

typedef struct      s_a
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*str;
}                   t_a;

/*
**     image_wolf3d.c
*/
void				ft_creat_windows_image(t_a *a);
int				wolf_keyboard(int keycode, t_a *a);

/*
**     main.c
*/
void				ft_error(char *str);
int					main(int argc, char **argv);

#endif
