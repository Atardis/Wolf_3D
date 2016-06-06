/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 10:16:36 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/10 10:16:38 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				verif_caract(char c)
{
	if (c == '.' || c == 's' || c == '1' || c == '2' || c == '3' || c == '4' ||\
		c == '5')
		return (1);
	return (0);
}

static void		ft_send_map(t_a *a, char *str, int y)
{
	int			i;
	int			x;

	i = 0;
	x = -1;
	while (str[i])
	{
		if (str[i] != ' ' && verif_caract(str[i]) == 1)
			a->map[y][++x] = str[i];
		i++;
	}
}

static void		ft_read_map(t_a *a, char *name)
{
	int			y;

	if ((a->fd2 = open(name, O_RDONLY)) == -1)
		ft_error("File Not Present / No Rights");
	close(a->fd1);
	y = -1;
	while (get_next_line(a->fd2, &a->line) > 0 && ++y < a->max_y)
	{
		ft_send_map(a, a->line, y);
		free(a->line);
	}
	free(a->line);
	close(a->fd2);
}

static void		ft_creat_map(t_a *a)
{
	int			y;
	int			x;

	if (!(a->map = (char **)ft_memalloc(sizeof(char *) * a->max_y)))
		ft_error("Probleme Malloc");
	y = -1;
	while (++y < a->max_y)
	{
		if (!(a->map[y] = (char *)ft_memalloc(sizeof(char) * a->max_x)))
			ft_error("Probleme Malloc");
		x = -1;
		while (++x < a->max_x)
			a->map[y][x] = '\0';
	}
}

void			ft_open_map(t_a *a, char *name)
{
	if ((a->fd1 = open(name, O_RDONLY)) == -1)
		ft_error("File Not Present / No Rights");
	while (get_next_line(a->fd1, &a->line) > 0)
	{
		if (a->max_y == 0)
			a->max_x = count_carac(a->line);
		if (a->max_y != 0)
			if (a->max_x != count_carac(a->line))
				ft_error("The Map is Invalid");
		a->max_y++;
		free(a->line);
	}
	free(a->line);
	if (a->max_x == 0 || a->max_y == 0)
		ft_error("The Map is Invalid");
	ft_creat_map(a);
	ft_read_map(a, name);
}
