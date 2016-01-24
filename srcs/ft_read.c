/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/24 18:24:39 by amoinier         ###   ########.fr       */
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
	if (!(tmp = (t_point ***)malloc(sizeof(tmp) * nline)))
		error();
	while (i != nline)
	{
		tmp[i] = p[i];
		i++;
	}
	free(p);
	if (!(p = (t_point ***)malloc(sizeof(p) * (nline + 1))))
		error();
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
	int		ret;
	char	*line;

	i = 0;
	point = (t_point ***)malloc(sizeof(point) * 1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		point[i] = init_point(line, i);
		point = ft_realloc(point, i + 1);
		i++;
	}
	if (ret > 0)
		error();
	point[0][0]->sizeline = i;
	return (point);
}
