/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 12:04:46 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/21 11:32:04 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
			tab[i][j]->px = (init->axex * i + (tab[i][j]->x * init->zoom));
			tab[i][j]->px -= ((tab[i][j]->z * init->axez) / 10) - init->movex;
			tab[i][j]->py = (init->axey * j + (tab[i][j]->y * init->zoom));
			tab[i][j]->py -= ((tab[i][j]->z * init->axez) / 10) - init->movey;
			if (col != 0x000000)
				col = 0xffffff - ((tab[i][j]->z * init->axez));
			pixel_put_image(init, tab[i][j]->px, tab[i][j]->py, col);
			j++;
		}
		i++;
	}
}

void	line1(t_env *init, int dxy[2], int xyi[2], int xy[2], int col)
{
	int	bre;
	int	i;

	i = 1;
	bre = dxy[0] / 2;
	while (i < dxy[0])
	{
		xy[0] += xyi[0];
		bre += dxy[1];
		if (bre >= dxy[0])
		{
			bre -= dxy[0];
			xy[1] += xyi[1];
		}
		pixel_put_image(init, xy[0], xy[1], col);
		i++;
	}
}

void	line2(t_env *init, int dxy[2], int xyi[2], int xy[2], int col)
{
	int	bre;
	int	i;

	i = 1;
	bre = dxy[1] / 2;
	while (i < dxy[1])
	{
		xy[1] += xyi[1];
		bre += dxy[0];
		if (bre >= dxy[1])
		{
			bre -= dxy[1];
			xy[0] += xyi[0];
		}
		pixel_put_image(init, xy[0], xy[1], col);
		i++;
	}
}

void	line(t_env *init, t_point **tab, int j, int col)
{
	int dxy[2];
	int xyi[2];
	int xy[2];

	xy[0] = tab[j]->px;
	xy[1] = tab[j]->py;
	dxy[0] = tab[j + 1]->px - tab[j]->px;
	dxy[1] = tab[j + 1]->py - tab[j]->py;
	xyi[0] = ( dxy[0] > 0 ) ? 1 : -1;
	xyi[1] = ( dxy[1] > 0 ) ? 1 : -1;
	dxy[0] = ft_valabs(dxy[0]);
	dxy[1] = ft_valabs(dxy[1]);
	if (dxy[0] > dxy[1])
		line1(init, dxy, xyi, xy, col);
	else
		line2(init, dxy, xyi, xy, col);
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

void	drawcol(t_env *init, t_point ***tab, int col)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	dx;
	int	dy;

	i = 0;
	while (i < tab[0][0]->sizeline - 1)
	{
		j = 0;
		while (j < tab[i][0]->sizecol)
		{
			k = 0;
			l = 0;
			dx = tab[i][j]->px - tab[i + 1][j]->px;
			dy = tab[i + 1][j]->py - tab[i][j]->py;
			while (k <= dy)
			{
				if (dy != 0)
					l = (dx * k) / dy;
				if (col != 0x000000)
					col = 0xffffff - ((tab[i][j]->z * init->axez));
				pixel_put_image(init, tab[i][j]->px - l, tab[i][j]->py + k, col);
				k++;
			}
			j++;
		}
		i++;
	}
}
