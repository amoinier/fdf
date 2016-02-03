/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:59:57 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/03 19:34:19 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_img	*ft_init_img(t_env *init)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(*img))))
		error();
	img->img = mlx_new_image(init->mlx, init->width, init->height);
	img->bpp = 0;
	img->sizel = 0;
	img->endn = 0;
	img->cimg = mlx_get_data_addr(img->img, &img->bpp, &img->sizel, &img->endn);
	return (img);
}

static	void	ft_initenv(t_env *init)
{
	init->width = 2250;
	init->height = 1250;
	init->movex = 300;
	init->movey = 300;
	init->axex = 0;
	init->axey = 0;
	init->axez = 2;
	init->zoom = 4;
	init->col = 0;
	init->img = ft_init_img(init);
}

static	int		ft_col(t_env *init, int color)
{
	if (init->col == 10)
		color = 0xffffff;
	else if (init->col == 1)
		color = 0xff0000;
	else if (init->col == 2)
		color = 0x00ff00;
	else if (init->col == 3)
		color = 0x0000ff;
	else if (init->col == 999)
		return (color);
	return (color);
}

void			pixel_put_image(t_env *init, int x, int y, int color)
{
	int		i;
	int		bpp;
	int		sizeline;
	char	*data;

	bpp = init->img->bpp;
	sizeline = init->img->sizel;
	data = init->img->cimg;
	color = ft_col(init, color);
	if (x < init->width && y < init->height && x > 0 && y > 0)
	{
		i = x * (bpp / 8) + y * sizeline;
		data[i] = color % 256;
		color /= 256;
		data[i + 1] = color % 256;
		color /= 256;
		data[i + 2] = color % 256;
	}
}

int				main(int ac, char **av)
{
	t_env	*init;

	if (ac == 2)
	{
		if (!(init = (t_env *)malloc(sizeof(*init))))
			error();
		init->point = ft_createstruct(av);
		init->mlx = mlx_init();
		ft_initenv(init);
		init->win = mlx_new_window(init->mlx, init->width, init->height, "FDF");
		init->lol = av[1];
		mlx_hook(init->win, 2, 0, key_hook, init);
		mlx_expose_hook(init->win, expose_hook, init);
		mlx_loop(init->mlx);
	}
	else
		error();
	return (0);
}
