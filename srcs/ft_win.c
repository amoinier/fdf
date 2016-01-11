/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 12:04:46 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/11 20:19:46 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			tab[i][j]->px = (50 + (tab[i][j]->x * 20));
			tab[i][j]->py = (50 + (tab[i][j]->y * 20));
			mlx_pixel_put(init->mlx, init->win, tab[i][j]->px, tab[i][j]->py, 0xff0000);
			j++;
		}
		i++;
	}
}

#include <stdio.h>

void	drawline(t_env *init, t_point ***tab)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	tt;
	int	ty;

	i = 0;
	while (i < tab[0][0]->sizeline)
	{
		j = 0;
		while (j < tab[i][0]->sizecol - 1)
		{
			k = 0;
			l = 0;
			tt = tab[i][j + 1]->px - tab[i][j]->px;
			ty = tab[i][j + 1]->py - tab[i][j]->py;
			while (k <= tt && l <= ty)
			{
				if (tt != 0 && ty != 0 && k % (tt/ty) == 0)
					l++;
				//printf("%d - %d\n", ty, tt);
				mlx_pixel_put(init->mlx, init->win, tab[i][j]->px + k, tab[i][j]->py + l, 0xffffff);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	drawcol(t_env *init, t_point ***tab)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	tt;
	int	ty;

	i = 0;
	while (i < tab[0][0]->sizeline - 1)
	{
		j = 0;
		while (j < tab[i][0]->sizecol)
		{
			k = 0;
			l = 0;
			tt = tab[i][j]->px - tab[i + 1][j]->px;
			ty = tab[i + 1][j]->py - tab[i][j]->py;
			while (k <= ty && l <= tt)
			{
				if (ty != 0 && tt != 0 && (k % (ty/tt)) == 0)
					l++;
//				printf("%d - %d\n", ty, tt);
				mlx_pixel_put(init->mlx, init->win, tab[i][j]->px - l, tab[i][j]->py + k, 0xffffff);
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
	button *= 1;
	x *= 1;
	y *= 1;
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
