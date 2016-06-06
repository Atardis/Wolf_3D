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

#ifndef WOLF3D_H
# define WOLF3D_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define BLACK 0x000000
# define BLUE 0x1900FE
# define GREEN 0x00FE5D
# define PINK 0xFF358B
# define RED 0xF90053
# define WHITE 0xFFFFFF
# define ORANGE 0xFEC300
# define YELLOW 0xF6FE00
# define BROWN 0xBD8D46
# define BLUEM 0x046380
# define ESC 53
# define PLUS 69
# define MINUS 78
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define W 13
# define S 1
# define A 0
# define D 2
# define R 15
# define C 8
# define P 35
# define V 9
# define M 46
# define SHIFT 257
# define PI 3.14159265
# define MAX_X 500
# define MAX_Y2 500
# define MAX_Y 1000
# define DATA1 a->data1
# define DATA2 a->data2
# define P2X a->p2x
# define P2Y a->p2y
# define P1X a->p1x
# define P1Y a->p1y
# define WALL a->dist_wall
# define KUP a->key_up
# define KODWN a->key_down
# define KLEFT a->key_left
# define KRIGHT a->key_right
# define KA a->key_a
# define KD a->key_d

# define UI unsigned int

typedef struct		s_a
{
	void			*mlx;
	void			*win;
	void			*img1;
	void			*img2;
	char			*data1;
	char			*data2;
	char			*str;
	char			*line;
	int				bpp1;
	int				bpp2;
	int				sl1;
	int				sl2;
	int				e;
	int				fd1;
	int				fd2;
	int				max_x;
	int				max_y;
	int				tmp;
	char			**map;
	double			x_start;
	double			y_start;
	int				dist_wall;
	double			pi;
	int				color;
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
	int				size;
	int				k;
	int				l;
	int				j;
	int				i;
	double			angle;
	double			save_angle;
	double			cos_angle;
	int				angle_cos;
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
	int				key_left;
	int				key_right;
	int				key_up;
	int				key_down;
	int				key_c;
	int				key_v;
	int				key_p;
	int				key_r;
	int				key_shift;
	int				safe;
	int				save_x;
	int				save_y;
	int				save_x2;
	int				save_y2;
	int				save_color;
	int				modif;
	int				side;
	int				speed;
}					t_a;

/*
**		image_wolf3d.c
*/
void				ft_creat_windows_image(t_a *a);
void				ft_init_key(t_a *a);
int					event_key_press(int keycode, t_a *a);
int					event_key_release(int keycode, t_a *a);

/*
**		main.c
*/
void				ft_print_map(t_a *a);
int					main(int argc, char **argv);

/*
**		map.c
*/
int					verif_caract(char c);
void				ft_open_map(t_a *a, char *name);

/*
**		move_wolf3d.c
*/
void				wolf_keyboard_move(t_a *a, int keycode);

/*
**		other.c
*/
int					count_carac(char *str);
void				ft_print_help(t_a *a);

/*
**		print_wall_wolf.c
*/
void				ft_print_wall_wolf(t_a *a);

/*
**		trace_line.c
*/
void				ligne(t_a *a, int c, int i);

/*
**		trace_line_angle.c
*/
void				ligne_angle(t_a *a);

/*
**		trace_line_verif.c
*/
void				ligne_verif(t_a *a);

/*
**		trace_wall.c
*/
int					print_skybox_and_ground(t_a *a);

/*
**		wolf_color.c
*/
void				ft_check_color_position_side(t_a *a);
void				ft_check_color_position_case(t_a *a);
void				ft_case_color(t_a *a, int y);

/*
**		wolf_hypotenuse.c
*/
void				hypotenuse(t_a *a, double i);

#endif
