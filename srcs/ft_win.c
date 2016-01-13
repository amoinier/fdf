/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 12:04:46 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/13 20:50:02 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw(void *mlx, void *win, int col)
{
	int	i;
	int	j;

	i = 250;
	while (i < 1)
	{
		j = 250;
		while (j < 1)
		{
			mlx_pixel_put(mlx, win, i, j, col);
			j++;
		}
		i++;
	}
}

void	draw42(t_env *init, t_point ***tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab[0][0]->sizeline)
	{
		j = 0;
		while (j < tab[i][0]->sizecol)
		{
			tab[i][j]->px = (150 + (tab[i][j]->x * 20) - tab[i][j]->z);
			tab[i][j]->py = (150 + (tab[i][j]->y * 20) - tab[i][j]->z);
			mlx_pixel_put(init->mlx, init->win, tab[i][j]->px, tab[i][j]->py, 0xff0000);
			j++;
		}
		i++;
	}
}

void	drawline(t_env *init, t_point ***tab)
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
				l = tab[i][j]->py + ((dy * k) / dx);
				mlx_pixel_put(init->mlx, init->win, tab[i][j]->px + k, l, 0xffffff);
				k++;
			}
			j++;
		}
		i++;
	}
}

int		valab(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

void	drawcol(t_env *init, t_point ***tab)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	dx;
	int	dy;
	int	i$j$k$l$dx$dy;

	i = 0;
	i$j$k$l$dx$dy = 0;
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
				if (dx != dy)
					l = tab[i][j]->px + ((valab(dx) * k) / dy);
				else if (dx == dy)
					l = tab[i][j]->px - ((valab(dx) * k) / dy);
				mlx_pixel_put(init->mlx, init->win, l, tab[i][j]->py + k, 0xffffff);
				k++;
			}
			j++;
		}
		i++;
	}
}

int		mouse_hook(int button, int x, int y, t_env *init)
{
	draw(init->mlx, init->win, 0x00FFFF);
	printf("%d - %d", x, y);
	button *= 1;
	return (0);
}

int		key_hook(int keycode, t_env *init)
{
	draw(init->mlx, init->win, 0x00FF00);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		expose_hook(t_env *init)
{
	draw(init->mlx, init->win, 0xFF00FF);
	return (0);
}
