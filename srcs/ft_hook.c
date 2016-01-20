/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:37:22 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/20 19:39:09 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_draw(t_env *init, int col)
{
	draw42(init, init->point, col);
	drawline(init, init->point, col);
	drawcol(init, init->point, col);
}

int		mouse_hook(int button, int x, int y, t_env *init)
{
	init->zoom *= 1;
	button *= 1;
	x *= 1;
	y *= 1;
	return (0);
}

int		key_hook(int keycode, t_env *init)
{
	//mlx_destroy_image(init->mlx, init->img->img);
	ft_draw(init, 0x000000);
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		init->movey -= 5;
	if (keycode == 125)
		init->movey += 5;
	if (keycode == 124)
		init->movex += 5;
	if (keycode == 123)
		init->movex -= 5;
	if (keycode == 13)
		init->axey--;
	if (keycode == 1)
		init->axey++;
	if (keycode == 0)
		init->axex--;
	if (keycode == 2)
		init->axex++;
	if (keycode == 16)
		init->axez += 1;
	if (keycode == 4)
		init->axez -= 1;
	if (keycode == 116)
		init->zoom++;
	if (keycode == 121)
		init->zoom--;
	ft_draw(init, 0xffffff);
	mlx_put_image_to_window(init->mlx, init->win, init->img->img, 1, 1);
	return (0);
}

int		expose_hook(t_env *init)
{
	init->zoom *= 1;
	return (0);
}
