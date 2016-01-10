/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 12:04:46 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/10 18:39:33 by amoinier         ###   ########.fr       */
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

void	draw42(t_env init, t_point ***tab, int line, int coln)
{
	int	i;
	int	j;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < coln)
		{
			ft_putchar('a');
			tab[i][j]->px = 350 - 9 * i + (tab[i][j]->x * 20) + (tab[i][j]->z);
			tab[i][j]->py = 350 + 5 * j + (tab[i][j]->y * 20) + (tab[i][j]->z);
			mlx_pixel_put(init.mlx, init.win, tab[i][j]->px, tab[i][j]->py, 0xff0000);
			j++;
		}
		i++;
	}
}

void	drawline(t_env init, t_point ***tab, int line, int coln)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	tt;
	int	ty;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < coln - 1)
		{
			k = 0;
			l = 0;
			while (tab[i][j + 1]->px != tab[i][j]->px + k)
			{
				tt = tab[i][j + 1]->px - tab[i][j]->px;
				ty = tab[i][j + 1]->py - tab[i][j]->py;
				if (k % (tt/ty) == 0)
					l++;
				mlx_pixel_put(init.mlx, init.win, tab[i][j]->px + k, tab[i][j]->py + l, 0xffffff);
				k++;
			}
			j++;
		}
		i++;
	}
}

#include <stdio.h>

void	drawcol(t_env init, t_point ***tab, int line, int coln)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	 tt;
	int	 ty;

	i = 0;
	while (i < line - 1)
	{
		j = 0;
		while (j < coln)
		{
			k = 0;
			l = 0;
			while (tab[i + 1][j]->py != tab[i][j]->py + k)
			{
				tt = tab[i][j]->px - tab[i + 1][j]->px;
				ty = tab[i + 1][j]->py - tab[i][j]->py;
				ft_putnbr(tt);
				ft_putchar('-');
				ft_putnbr(ty);
				ft_putchar('\n');
				if (k % (ty/tt) == 0)
					l++;
				mlx_pixel_put(init.mlx, init.win, tab[i][j]->px - l, tab[i][j]->py + k, 0xffffff);
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
