/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 16:59:57 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/11 20:22:15 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point		***ft_init_t_point(int nbline, char **str)
{
	int		i;
	int		j;
	int		lline;
	t_point	***tab;

	lline = ft_longline(str);
	i = 0;
	if (!(tab = (t_point ***)malloc(sizeof(tab) * (nbline + 1))))
		return (NULL);
	while (i <= nbline)
	{
		j = 0;
		tab[i] = (t_point **)malloc(sizeof(tab[i]) * (lline + 1));
		while (j <= lline)
		{
			tab[i][j] = NULL;
			j++;
		}
		i++;
	}
	return (tab);
}

t_point		*ft_pointnew(int x, int y, int z)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		return (NULL);
	point->x = x;
	point->y = y;
	point->z = z;
	point->px = 0;
	point->py = 0;
	point->sizeline = 0;
	point->sizecol = 0;
	return (point);
}

t_point		***ft_createstruct(int *line, int *coln, char **av)
{
	char	**str[2];
	t_point	***point;
	int		**tab;
	int		i;
	int		j;

	str[0] = ft_strsplit(ft_read(av), '\n');
	*line = ft_countnbline(str[0]);
	tab = (int **)malloc(sizeof(tab) * (*line + 1));
	point = ft_init_t_point(*line, str[0]);
	i = 0;
	while (i < *line)
	{
		j = 0;
		*coln = ft_countcara(str[0][i]);
		str[1] = ft_strsplit(str[0][i], 32);
		tab[i] = ft_toint(str[1], *coln);
		while (j < *coln)
		{
			point[i][j] = ft_pointnew(j, i, tab[i][j]);
			point[i][j]->sizecol = *coln;
			point[i][j]->sizeline = *line;
			j++;
		}
		i++;
	}
	return (point);
}

int		main(int ac, char **av)
{
	t_env	*init;
	t_point	***point;
	int		line;
	int		coln;

	if (ac == 2)
	{
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
//		mlx_mouse_hook(init.win, mouse_hook, init);
		mlx_expose_hook(init->win, expose_hook, init);
		mlx_loop(init->mlx);
	}
	return (0);
}
