/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:42:35 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/22 21:19:47 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_pointnew(int x, int y, int z, int coln)
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
	point->sizecol = coln;
	return (point);
}

t_point	**init_point(char *line, int j)
{
	int		i;
	int		coln;
	char	**s;
	t_point	**point;

	i = 0;
	coln = ft_countcara(line);
	s = ft_strsplit(line, 32);
	point = (t_point **)malloc(sizeof(*point) * (coln + 1));
	while (i < coln)
	{
		point[i] = ft_pointnew(i, j, ft_atoi(s[i]), coln);
		i++;
	}
	point[i] = NULL;
	return (point);
}
