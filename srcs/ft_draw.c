/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 12:04:46 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/22 21:14:59 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static	void	draw1(t_env *init, int dxy[2], int xyi[2], int xy[2], int col)
{
	int	bre;
	int	i;

	i = 0;
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

static	void	draw2(t_env *init, int dxy[2], int xyi[2], int xy[2], int col)
{
	int	bre;
	int	i;

	i = 0;
	bre = dxy[1] / 2;
	while (i < dxy[1])
	{
		xy[1] += xyi[1];
		bre += dxy[0];
		if (bre > dxy[1])
		{
			bre -= dxy[1];
			xy[0] += xyi[0];
		}
		pixel_put_image(init, xy[0], xy[1], col);
		i++;
	}
}

void			line(t_env *init, t_point **tab, int j, int col)
{
	int dxy[2];
	int xyi[2];
	int xy[2];

	xy[0] = tab[j]->px;
	xy[1] = tab[j]->py;
	dxy[0] = tab[j + 1]->px - tab[j]->px;
	dxy[1] = tab[j + 1]->py - tab[j]->py;
	if (dxy[0] > 0)
		xyi[0] = 1;
	else
		xyi[0] = -1;
	if (dxy[1] > 0)
		xyi[1] = 1;
	else
		xyi[1] = -1;
	dxy[0] = ft_valabs(dxy[0]);
	dxy[1] = ft_valabs(dxy[1]);
	if (dxy[0] > dxy[1])
		draw1(init, dxy, xyi, xy, col);
	else
		draw2(init, dxy, xyi, xy, col);
}

void			column(t_env *init, t_point ***tab, int ij[2], int col)
{
	int dxy[2];
	int xyi[2];
	int xy[2];
	int	i;
	int	j;

	i = ij[0];
	j = ij[1];
	xy[0] = tab[i][j]->px;
	xy[1] = tab[i][j]->py;
	dxy[0] = tab[i + 1][j]->px - tab[i][j]->px;
	dxy[1] = tab[i + 1][j]->py - tab[i][j]->py;
	if (dxy[0] > 0)
		xyi[0] = 1;
	else
		xyi[0] = -1;
	xyi[1] = -1;
	if (dxy[1] > 0)
		xyi[1] = 1;
	dxy[0] = ft_valabs(dxy[0]);
	dxy[1] = ft_valabs(dxy[1]);
	if (dxy[0] > dxy[1])
		draw1(init, dxy, xyi, xy, col);
	else
		draw2(init, dxy, xyi, xy, col);
}
