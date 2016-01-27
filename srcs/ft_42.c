/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:12:40 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/27 20:18:51 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static	void	drawcol(t_env *init, t_point ***tab, int ij[2])
{
	ij[0]--;
	column(init, tab, ij);
}

static	void	drawline(t_env *init, t_point ***tab, int ij[2])
{
	int	j;
	int	i;

	j = ij[1] - 1;
	i = ij[0];
	line(init, tab[i], ij);
}

void			draw(t_env *init, t_point ***tab)
{
	int	i;
	int	j;
	int	ij[2];

	i = 0;
	while (i < tab[0][0]->sizeline)
	{
		j = 0;
		while (j < tab[i][0]->sizecol && (ij[1] = j) == j)
		{
			tab[i][j]->px = ((tab[i][j]->x * init->zoom));
			tab[i][j]->px -= ((tab[i][j]->z * init->axez) / 10) - init->movex;
			tab[i][j]->py = ((tab[i][j]->y * init->zoom));
			tab[i][j]->py -= ((tab[i][j]->z * init->axez) / 10) - init->movey;
			//tab[i][j]->px = ((tab[i][j]->px - tab[i][tab[0][0]->sizecol / 2]->px) * cos(init->axex) - (tab[i][j]->py - tab[i][tab[0][0]->sizecol / 2]->py) * sin(init->axex)) + tab[0][tab[0][0]->sizecol / 2]->px;
			ij[0] = i;
			if (j > 0)
				drawline(init, tab, ij);
			if (i > 0 && j < tab[i - 1][0]->sizecol)
				drawcol(init, tab, ij);
			j++;
		}
		i++;
	}
}
/*
xB = xA * cos( β ) - yA * sin( β ) // include <math.h>
yB = xA * sin( β ) + yA * cos( β )
zB = zA
*/
