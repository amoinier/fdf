/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:12:40 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/01 20:08:54 by amoinier         ###   ########.fr       */
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
	while (i < tab[0][0]->sizeline && (i * init->zoom + init->movey) <= init->height)
	{
		j = 0;
		while (j < tab[i][0]->sizecol && (ij[1] = j) == j &&
		(j * init->zoom + init->movex) <= init->width)
		{
			tab[i][j]->px = tab[i][j]->x * init->zoom + init->movex;
			tab[i][j]->px -= ((tab[i][j]->z * init->axez) / 10);
			tab[i][j]->py = tab[i][j]->y * init->zoom + init->movey;
			tab[i][j]->py -= ((tab[i][j]->z * init->axez) / 10);
			tab[i][j]->px += (i * init->axex);
			tab[i][j]->py += (j * init->axey);
			ij[0] = i;
			if (j > 0 && tab[i][j]->px > 0 && tab[i][j]->py > 0)
				drawline(init, tab, ij);
			if (i > 0 && j < tab[i - 1][0]->sizecol &&
				tab[i][j]->px > 0 && tab[i][j]->py > 0)
				drawcol(init, tab, ij);
			j++;
		}
		i++;
	}
}
//tab[i][j]->px = (((tab[i][j]->x - tab[i][tab[0][0]->sizecol / 2]->x) * init->zoom) * cos(init->axex) + (tab[i][tab[0][0]->sizecol / 2]->x * init->zoom) - (((tab[i][j]->y - tab[i][tab[0][0]->sizecol / 2]->y) * init->zoom) * sin(init->axex)) + ((tab[i][j]->y - tab[i][tab[0][0]->sizecol / 2]->y) * init->zoom));
//tab[i][j]->py = (((tab[i][j]->y - tab[tab[0][0]->sizeline / 2][j]->y) * init->zoom) * cos(init->axey) + (tab[tab[0][0]->sizeline / 2][j]->y * init->zoom) - ((tab[i][j]->x - tab[tab[0][0]->sizeline / 2][j]->x) * init->zoom) * sin(init->axey));
