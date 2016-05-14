#include "../includes/wolf3d.h"

int				ft_print_case(t_a *a)
{
	int			tmp_y;
	int			x;

	tmp_y = a->y_start;
	x = a->x_start;
	while (a->map[tmp_y][x] != '1')
		tmp_y--;
	return (a->y_start - tmp_y);
}

void			ft_localisation_start(t_a *a)
{
	ft_putnbr_end(a->x_start);
	ft_putnbr_end(a->y_start);
	ft_print_case(a);
}