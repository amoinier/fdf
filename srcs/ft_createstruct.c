/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:42:35 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/15 11:00:24 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point     ***ft_init_t_point(int nbline, char **str)
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
	point->movex = 0;
	point->movey = 0;
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
