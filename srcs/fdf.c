/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:59:57 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/18 20:42:05 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env	*init;
	int		line;
	int		coln;

	if (ac == 2)
	{
		line = 0;
		coln = 0;
		init = (t_env *)malloc(sizeof(*init));
		init->mlx = mlx_init();
		init->win = mlx_new_window(init->mlx, 1000, 1000, "JMAIQUEZ <3");
		init->point = ft_createstruct(&line, &coln, av);
		mlx_key_hook(init->win, key_hook, init);
		mlx_do_key_autorepeaton(init->mlx);
		mlx_mouse_hook(init->win, mouse_hook, init);
		mlx_expose_hook(init->win, expose_hook, init);
		mlx_loop(init->mlx);
	}
	return (0);
}
