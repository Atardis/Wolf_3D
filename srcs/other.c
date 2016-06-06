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
