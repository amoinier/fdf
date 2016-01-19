/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:59:57 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/19 18:55:19 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_initenv(t_env *init)
{
	if (!(init->img = (t_img *)malloc(sizeof(*init->img))))
		return ;
	init->width = 1000;
	init->height = 1000;
	init->movex = 0;
	init->movey = 0;
	init->axex = 0;
	init->axey = 0;
	init->axez = 10;
	init->zoom = 1;
	init->img->img = mlx_new_image(init->mlx, init->width, init->height);
	init->img->cimg = mlx_get_data_addr(init->img->img, &init->img->bpp, &init->img->sizel, &init->img->endian);
	ft_putstr(init->img->cimg);
}

void	mlx_pxl_img()
{

}

int		main(int ac, char **av)
{
	t_env	*init;
	int		line;
	int		coln;

	if (ac == 2)
	{
		line = 0;
		coln = 0;
		if (!(init = (t_env *)malloc(sizeof(*init))))
			return (0);
		init->mlx = mlx_init();
		ft_initenv(init);
		init->win = mlx_new_window(init->mlx, init->width, init->height, "JMAIQUEZ <3");
		init->point = ft_createstruct(&line, &coln, av);
		mlx_put_image_to_window(init->mlx, init->win, init->img->img, 0, 0);
		mlx_hook(init->win, 2, 0, key_hook, init);
		mlx_mouse_hook(init->win, mouse_hook, init);
		mlx_expose_hook(init->win, expose_hook, init);
		mlx_loop(init->mlx);
	}
	return (0);
}
