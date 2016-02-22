/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:13:16 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/04 12:21:00 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_clear_img(t_env *init)
{
	int	size;

	size = init->width * init->height * 4 - 1;
	ft_bzero(init->img->cimg, size);
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
	if (init->col > 1000)
		color = init->col;
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
