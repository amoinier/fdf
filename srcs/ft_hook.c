/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:37:22 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/23 15:11:24 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_draw(t_env *init, int col)
{
	draw(init, init->point, col);
}

static	void	ft_clear_img(t_env *init)
{
	int		off_y;

	off_y = init->width * init->height * 4 - 1;
	init->img->cimg = ft_memset(init->img->cimg, 0, off_y);
}

static	void	keypad(int keycode, t_env *init)
{
	if (keycode == 126)
		init->movey -= 5;
	if (keycode == 125)
		init->movey += 5;
	if (keycode == 124)
		init->movex += 5;
	if (keycode == 123)
		init->movex -= 5;
}

int				key_hook(int keycode, t_env *init)
{
	if (keycode == 53)
	{
		mlx_destroy_image(init->mlx, init->img->img);
		exit(0);
	}
	ft_clear_img(init);
	keypad(keycode, init);
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
