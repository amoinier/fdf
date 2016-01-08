/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:59:57 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/08 20:45:42 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	draw(void *mlx, void *win, int col)
{
	int	i;
	int	j;

	i = 250;
	while (i < 500)
	{
		j = 250;
		while (j < 500)
		{
			mlx_pixel_put(mlx, win, i, j, col);
			j++;
		}
		i++;
	}
}

int		mouse_hook(int button, int x, int y, t_env *init)
{
	draw(init->mlx, init->win, 0x00FFFF);
	printf("mouse %d: x%d y%d", button, x, y);
	return (0);
}

int		key_hook(int keycode, t_env *init)
{
	draw(init->mlx, init->win, 0xFFFF00);
	printf("key :%d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

int		expose_hook(t_env *init)
{
	draw(init->mlx, init->win, 0xFF00FF);
	return (0);
}

int		main(int ac, char **av)
{
	//t_env	init;
	char	**str;
	char	*s;
	char	***str2;
//	t_point	***tab;
	int		**tab;
	int		i;
	int			line;

	ac *= 1;
	i = 0;
	av[0][0] = av[0][1];
	s = ft_read(av);
	str = ft_strsplit(s, '\n');
	line = ft_countnbline(str);
	str2 = (char ***)malloc(sizeof(str2) * (line + 1));
	tab = (int **)malloc(sizeof(tab) * (line + 1));
	while (i < line)
	{
		str2[i] = ft_strsplit(str[i], 32);
		tab[i] = ft_toint(str2[i], ft_countcara(str[0]));
		i++;
	}
	ft_printi(tab);
/*	init.mlx = mlx_init();
	init.win = mlx_new_window(init.mlx, 1000, 1000, "JMAIQUEZ <3");
	mlx_mouse_hook(init.win, mouse_hook, &init);
	mlx_key_hook(init.win, key_hook, &init);
	mlx_expose_hook(init.win, expose_hook, &init);
	mlx_loop(init.mlx);*/
	return (0);
}
