/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstruct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:42:35 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/27 13:36:37 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*ft_pointnew(int x, int y, int z, int coln)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(*point))))
		error();
	point->x = x;
	point->y = y;
	point->z = z;
	point->px = 0;
	point->py = 0;
	point->sizeline = 0;
	point->sizecol = coln;
	point->col = 0xffffff;
	return (point);
}
/*
if z >>> (256 * 256 + 256 * 16 + 256 * 1)
if z >-  (64 * 256 + 40 * 16 + 0 * 1)
if z = 0 (50 * 256 + 256 * 16 + 0 * 1)
if z <-  (0 * 256 + 12 * 16 + 112 * 256)
if z <<< (0 * 256 + 5 * 16 + 256 * 1)
*/
t_point	**init_point(char *line, int j)
{
	int		i;
	int		coln;
	char	**s;
	t_point	**point;

	i = 0;
	coln = ft_countcara(line);
	s = ft_strsplit(line, 32);
	if (!(point = (t_point **)malloc(sizeof(*point) * (coln + 1))))
		error();
	while (i < coln)
	{
		point[i] = ft_pointnew(i, j, ft_atoi(s[i]), coln);
		i++;
	}
	free(s);
	s = NULL;
	return (point);
}
