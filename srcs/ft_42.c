/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:12:40 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/22 21:14:21 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawcol(t_env *init, t_point ***tab, int col)
{
	int	i;
	int	j;
	int	ij[2];

	i = 0;
	while (i < tab[0][0]->sizeline - 1)
	{
		j = 0;
		while (j < tab[i][0]->sizecol)
		{
			ij[0] = i;
			ij[1] = j;
			if (tab[i + 1][j])
				column(init, tab, ij, col);
			j++;
		}
		i++;
	}
}

void	drawline(t_env *init, t_point ***tab, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab[0][0]->sizeline)
	{
		j = 0;
		while (j < tab[i][0]->sizecol - 1)
		{
			line(init, tab[i], j, col);
			j++;
		}
		i++;
	}
}

void	draw42(t_env *init, t_point ***tab, int col)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab[0][0]->sizeline)
	{
		j = 0;
		while (j < tab[i][0]->sizecol)
		{
			tab[i][j]->px = (init->axex + (tab[i][j]->x * init->zoom));
			tab[i][j]->px -= ((tab[i][j]->z * init->axez) / 10) - init->movex;
			tab[i][j]->py = (init->axey + (tab[i][j]->y * init->zoom));
			tab[i][j]->py -= ((tab[i][j]->z * init->axez) / 10) - init->movey;
			if (col != 0x000000)
				col = 0xffffff - ((tab[i][j]->z * init->axez));
			pixel_put_image(init, tab[i][j]->px, tab[i][j]->py, col);
			j++;
		}
		i++;
	}
}
