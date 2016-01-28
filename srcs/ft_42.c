/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:12:40 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/28 17:16:05 by amoinier         ###   ########.fr       */
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
			tab[i][j]->px = (((tab[i][j]->x - tab[i][tab[0][0]->sizecol / 2]->x) * init->zoom) * cos(init->axex) + (tab[i][tab[0][0]->sizecol / 2]->x * init->zoom) - ((tab[i][j]->y - tab[i][tab[0][0]->sizecol / 2]->y) * init->zoom) * sin(init->axex));
			tab[i][j]->px += init->movex;
			tab[i][j]->px -= ((tab[i][j]->z * init->axez) / 10);
			tab[i][j]->py = (((tab[i][j]->y - tab[tab[0][0]->sizeline / 2][0]->y) * init->zoom) * cos(init->axey) + (tab[tab[0][0]->sizeline / 2][0]->y * init->zoom) - ((tab[i][j]->x - tab[tab[0][0]->sizeline / 2][0]->y) * init->zoom) * sin(init->axey));
			tab[i][j]->py += init->movey;
			tab[i][j]->py -= ((tab[i][j]->z * init->axez) / 10);
			//tab[i][j]->px -= (i * init->axex);
			//tab[i][j]->py -= (j * init->axey);
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
(init->movex + tab[i][0]->x + ((tab[i][0]->sizecol / 2) * init->zoom))
xB = xA * cos( β ) - yA * sin( β ) // include <math.h>
yB = xA * sin( β ) + yA * cos( β )
zB = zA
*/
