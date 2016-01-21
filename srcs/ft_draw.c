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

void	drawline(t_env *init, t_point ***tab, int col)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	dx;
	int	dy;

	i = 0;
	while (i < tab[0][0]->sizeline)
	{
		j = 0;
		while (j < tab[i][0]->sizecol - 1)
		{
			k = 0;
			l = 0;
			dx = tab[i][j + 1]->px - tab[i][j]->px;
			dy = tab[i][j + 1]->py - tab[i][j]->py;
			while (k <= dx)
			{
				if (dx != 0)
					l = (dy * k) / dx;
				if (col != 0x000000)
					col = 0xffffff - ((tab[i][j]->z * init->axez));
				pixel_put_image(init, tab[i][j]->px + k, tab[i][j]->py + l, col);
				k++;
			}
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
