/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahubaul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 06:39:57 by gahubaul          #+#    #+#             */
/*   Updated: 2016/05/08 06:39:59 by gahubaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				count_carac(char *str)
{
	int			i;
	int			count;

	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i] != ' ' && verif_caract(str[i]) == 1)
			count++;
		else if (verif_caract(str[i]) == 1)
			ft_error("The Map is Invalid");
	}
	return (count);
}

void			ft_print_help(t_a *a)
{
	char		*str;

	(void)a;
	str = "\033[33m-------------------------";
	ft_putendl(str);
	str = "\033[31mHELP  WOLF3D  GAHUBAUL";
	ft_putendl(str);
	str = "\033[33m-------------------------";
	ft_putendl(str);
	str = "\033[35mTouche de deplacement ( W,S,A,D ) ( R activer )";
	ft_putendl(str);
	str = "Touche de deplacement ( UP,DOWN,LEFT,RIGHT ) ( R desactiver )";
	ft_putendl(str);
	str = "Touche de vision ( <-,-> ) ( R activer)";
	ft_putendl(str);
	str = "Touche de deplacement ( A,D ) ( R desactiver)";
	ft_putendl(str);
	str = "Deplacement plus lent (Maintenir SHIFT enfoncer)";
	ft_putendl(str);
	str = "Intervertir les Touche de Deplacement ( R )";
	ft_putendl(str);
	str = "Touche C pour changer les couleurs  ( C )";
	ft_putendl(str);
	str = "ESC quite le programme ( ESC )";
	ft_putendl(str);
}
