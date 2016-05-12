#include "../includes/wolf3d.h"

void		ft_localisation_start(t_a *a)
{
	int		y;
	int		x;
	int		tmp_y;

	y = -1;
	while (++y < MAX_Y)
	{
		x = -1;
		while (++x < MAX_X)
		{
			if (a->map[y][x] == 6)
			{
				a->x_start = x;
				a->y_start = y;
			}
		}
	}
	tmp_y = a->y_start;
	while (a->map[tmp_y][a->x_start] != 1)
		tmp_y--;
	while (1)
		;
	a->dist_wall = 64 * (a->y_start - tmp_y);
}