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

int				count_carac(char *str)
{
	int 	i;
	int		count;

	i = 0;
	count = 0;
	while(str[i])
	{
		if (ft_isdigit(str[i]) == 1 || str[i] == ' ' || str[i] == '\n' || str[i] == '-')
		{
			if (ft_isdigit(str[i]) == 1)
				count++;
			i++;
		}
		else if ((ft_isdigit(str[i]) == 0) && str[i] != ' ' && str[i] != '\n' && str[i] != '-')
			ft_error("The Map is Invalid");
	}
	return (count);
}

static void		ft_send_map(t_a *a, char *str, int y)
{
	int 	i;
	int		x;

	i = 0;
	x = -1;
	while(str[i])
	{
		if (ft_isdigit(str[i]) == 1)
			a->map[y][++x] = ft_atoi_re(str, i);
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
	while (get_next_line(a->fd2, &a->line) > 0 && ++y < a->size_y)
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

	if (!(a->map = (int **)ft_memalloc(sizeof(int *) * a->size_y)))
		ft_error("Probleme Malloc");
	y = -1;
	while (++y < a->size_y)
	{
		if (!(a->map[y] = (int *)ft_memalloc(sizeof(int) * a->size_x)))
			ft_error("Probleme Malloc");
		x = -1;
		while (++x < a->size_x)
			a->map[y][x] = 0;
	}
}

void			ft_open_map(t_a *a, char *name)
{
	if ((a->fd1 = open(name, O_RDONLY)) == -1)
		ft_error("File Not Present / No Rights");
	while (get_next_line(a->fd1, &a->line) > 0)
	{
		if (a->size_y == 0)
			a->size_x = count_carac(a->line);
		if (a->size_y != 0)
			if (a->size_x != count_carac(a->line))
 				ft_error("The Map is Invalid");
		a->size_y++;
		free(a->line);
	}
	free(a->line);
	if (a->size_x == 0 || a->size_y == 0)
		ft_error("The Map is Invalid");
	ft_creat_map(a);
	ft_read_map(a, name);
}
