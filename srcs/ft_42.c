/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:12:40 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/24 15:58:38 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	drawcol(t_env *init, t_point ***tab, int ij[2], int col)
{
	int	i;
	int	j;
	
	i = ij[0];
	j = ij[1];
	column(init, tab,ij, col);
}

void	drawline(t_env *init, t_point ***tab, int ij[2], int col)
{
	int	j;
	int	i;

	j = ij[1];
	i = ij[0];
	line(init, tab[i], j, col);
}

void	draw(t_env *init, t_point ***tab, int col)
{
	int	i;
	int	j;
	int	ij[2];

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
			ij[0] = i;
			ij[1] = j;
			if (j > 0)
			{
				ij[1]--;
				drawline(init, tab, ij, col);
				ij[1]++;
			}
			if (i > 0 && j < tab[i - 1][0]->sizecol)
			{
				ij[0]--;
				drawcol(init, tab, ij, col);
			}
			
			j++;
		}
		i++;
	}
}
