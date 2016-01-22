/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/22 21:22:01 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_point		***ft_realloc(t_point ***p, int nline)
{
	t_point	***tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = (t_point ***)malloc(sizeof(tmp) * nline);
	while (i != nline)
	{
		tmp[i] = p[i];
		i++;
	}
	free(p);
	p = (t_point ***)malloc(sizeof(p) * (nline + 1));
	while (j != nline)
	{
		p[j] = tmp[j];
		j++;
	}
	free(tmp);
	return (p);
}

t_point				***ft_createstruct(char **av)
{
	t_point	***point;
	int		fd;
	int		i;
	char	*line;

	i = 0;
	point = (t_point ***)malloc(sizeof(point) * 1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		point[i] = init_point(line, i);
		point = ft_realloc(point, i + 1);
		i++;
	}
	point[0][0]->sizeline = i;
	return (point);
}
