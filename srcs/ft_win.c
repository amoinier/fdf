/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 12:04:46 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/09 18:16:43 by amoinier         ###   ########.fr       */
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

void	draw42(void	*mlx, void *win, int col, t_point ***tab, int line, int coln)
{
	int	i;
	int	j;

	i = 0;
	while (i < line)
	{
		j = 0;
		while (j < coln)
		{
			mlx_pixel_put(mlx, win, 350 - 9 * i +  (tab[i][j]->x * 20), 350 + 5 * j + (tab[i][j]->y * 20), col);
			j++;
		}
		i++;
	}
}

#include <stdio.h>

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
