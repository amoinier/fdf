/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:59:57 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/15 11:05:29 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	*init;
	t_point	***point;
	int		line;
	int		coln;
	int		*xy[2];

	if (ac == 2)
	{
		xy[0] = 0;
		xy[1] = 0;
		line = 0;
		coln = 0;
		point = ft_createstruct(&line, &coln, av);
		init = (t_env *)malloc(sizeof(init));
		init->mlx = mlx_init();
		init->win = mlx_new_window(init->mlx, 1000, 1000, "JMAIQUEZ <3");
		draw42(init, point);
		drawline(init, point);
		drawcol(init, point);
		mlx_key_hook(init->win, key_hook, init);
		mlx_mouse_hook(init->win, mouse_hook, init);
		mlx_expose_hook(init->win, expose_hook, init);
		mlx_loop(init->mlx);
	}
	return (0);
}
