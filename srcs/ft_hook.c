/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:37:22 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/04 12:12:47 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	keypad(int keycode, t_env *init)
{
	if (keycode == 126)
		init->movey -= ((init->zoom + 1) * 2);
	if (keycode == 125)
		init->movey += ((init->zoom + 1) * 2);
	if (keycode == 124)
		init->movex += ((init->zoom + 1) * 2);
	if (keycode == 123)
		init->movex -= ((init->zoom + 1) * 2);
	if (keycode == 116)
		init->zoom++;
	if (keycode == 121)
		init->zoom--;
}

static	void	keycol(int keycode, t_env *init)
{
	if (keycode == 75)
		init->col = 666;
	if (keycode == 67)
		init->col = 999;
	if (keycode == 82)
		init->col = 10;
	if (keycode == 83)
		init->col = 1;
	if (keycode == 84)
		init->col = 2;
	if (keycode == 85)
		init->col = 3;
}

int				mouse_hook(int button, int x, int y, t_env *init)
{
	button = 1;
	init->col = bonus_mouse(x, y, init);
	ft_clear_img(init);
	draw(init, init->point);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	ft_str_win(init);
	return (0);
}

int				key_hook(int keycode, t_env *init)
{
	if (keycode == 53)
	{
		mlx_destroy_image(init->mlx, init->img->img);
		mlx_destroy_window(init->mlx, init->win);
		exit(0);
	}
	ft_clear_img(init);
	keypad(keycode, init);
	keycol(keycode, init);
	if (keycode == 13)
		init->axey -= 1;
	if (keycode == 1)
		init->axey += 1;
	if (keycode == 0)
		init->axex -= 1;
	if (keycode == 2)
		init->axex += 1;
	if (keycode == 16)
		init->axez += 1;
	if (keycode == 4)
		init->axez -= 1;
	draw(init, init->point);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
	ft_str_win(init);
	return (0);
}

int				expose_hook(t_env *init)
{
	draw(init, init->point);
	return (0);
}
