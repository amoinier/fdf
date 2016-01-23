/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 21:12:40 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/23 12:38:09 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	drawcol(t_env *init, t_point ***tab, int ij[2], int col)
{
	int	i;

	i = ij[0];
	if (i >= 1)
	{
		i--;
		ij[0]--;
		column(init, tab, ij, col);
		ij[0]++;
		i++;
	}
}

static	void	drawline(t_env *init, t_point ***tab, int ij[2], int col)
{
	int	i;
	int	j;

	i = ij[0];
	j = ij[1];
	if (j >= 1)
	{
		j--;
		line(init, tab[i], j, col);
		j++;
	}
}

void			draw(t_env *init, t_point ***tab, int col)
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
			ij[0] = i;
			ij[1] = j;
			tab[i][j]->px = (init->axex + (tab[i][j]->x * init->zoom));
			tab[i][j]->px -= ((tab[i][j]->z * init->axez) / 10) - init->movex;
			tab[i][j]->py = (init->axey + (tab[i][j]->y * init->zoom));
			tab[i][j]->py -= ((tab[i][j]->z * init->axez) / 10) - init->movey;
			//pixel_put_image(init, tab[i][j]->px, tab[i][j]->py, col);
			drawline(init, tab, ij, col);
			drawcol(init, tab, ij, col);
			j++;
		}
		i++;
	}
}
