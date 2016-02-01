/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:37:22 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/01 20:11:13 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	void	ft_clear_img(t_env *init)
{
	int		size;

	size = init->width * init->height * 4 - 1;
	ft_bzero(init->img->cimg, size);
}

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
