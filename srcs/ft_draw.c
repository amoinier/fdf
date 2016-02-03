/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 12:04:46 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/03 19:35:04 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static	void	draw1(t_env *init, int dxy[2], int xyi[2], int ij[2])
{
	int	bre;
	int	i;
	int	x;
	int	y;
	int	col;

	col = init->point[ij[0]][ij[1]]->col;
	x = init->point[ij[0]][ij[1]]->px;
	y = init->point[ij[0]][ij[1]]->py;
	i = 0;
	bre = dxy[0] / 2;
	while (i < dxy[0])
	{
		x += xyi[0];
		bre += dxy[1];
		if (bre >= dxy[0])
		{
			bre -= dxy[0];
			y += xyi[1];
		}
		pixel_put_image(init, x, y, col);
		i++;
	}
}

static	void	draw2(t_env *init, int dxy[2], int xyi[2], int ij[2])
{
	int	bre;
	int	i;
	int	x;
	int	y;
	int	col;

	col = init->point[ij[0]][ij[1]]->col;
	x = init->point[ij[0]][ij[1]]->px;
	y = init->point[ij[0]][ij[1]]->py;
	i = 0;
	bre = dxy[1] / 2;
	while (i < dxy[1])
	{
		y += xyi[1];
		bre += dxy[0];
		if (bre > dxy[1])
		{
			bre -= dxy[1];
			x += xyi[0];
		}
		pixel_put_image(init, x, y, col);
		i++;
	}
}

void			line(t_env *init, t_point **tab, int ij[2])
{
	int dxy[2];
	int xyi[2];
	int	j;

	j = ij[1] - 1;
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
	ij[1]--;
	if (dxy[0] > dxy[1])
		draw1(init, dxy, xyi, ij);
	else
		draw2(init, dxy, xyi, ij);
	ij[1]++;
}

void			column(t_env *init, t_point ***tab, int ij[2])
{
	int dxy[2];
	int xyi[2];
	int	i;
	int	j;

	i = ij[0];
	j = ij[1];
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
		draw1(init, dxy, xyi, ij);
	else
		draw2(init, dxy, xyi, ij);
}
