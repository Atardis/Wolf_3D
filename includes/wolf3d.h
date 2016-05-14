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
#include <fcntl.h>


# define ESC 53
# define PLUS 69
# define MINUS 78
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define W 13
# define S 1
# define A 0
# define D 2

# define MAX_X 750
# define MAX_Y 750

typedef struct      s_a
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	char			*str;
	char			*line;
	int				bpp;
	int				sl;
	int				e;
	int				fd1;
	int				fd2;
	int				max_x;
	int				max_y;
	char			**map;
	double			x_start;
	double			y_start;
	int				dist_wall;
	
	int				p1x;
	int				p2x;
	int				p1y;
	int				p2y;
	int				bx;
	int				by;
	int				bdx;
	int				bdy;
	int				bxinc;
	int				byinc;
	int				bi;
}                   t_a;

/*
**		image_wolf3d.c
*/
void				ft_creat_windows_image(t_a *a);
int					wolf_keyboard(int keycode, t_a *a);
int					wolf_mouse(int keycode, int x, int y, t_a *a);

/*
**		localisation.c
*/
int					ft_print_case(t_a *a);
void				ft_localisation_start(t_a *a);

/*
**		main.c
*/
int					main(int argc, char **argv);

/*
**		map.c
*/
void				ft_open_map(t_a *a, char *name);
int					count_carac(char *str);

/*
**		trace_line.c
*/
void				ligne(t_a *a, int c);

/*
**		trace_wall.c
*/
void				print_skybox_and_ground(t_a *a);

#endif
