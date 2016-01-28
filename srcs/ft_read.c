/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/28 15:14:39 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	t_point		***ft_realloc(t_point ***p, int nline)
{
	t_point	***tmp;
	int		i;

	i = 0;
	if (!(tmp = (t_point ***)malloc(sizeof(tmp) * (nline + 1))))
		error();
	while (i != nline)
	{
		tmp[i] = p[i];
		i++;
	}
	free(p);
	p = tmp;
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
	if (!(point = (t_point ***)malloc(sizeof(point) * 1)))
		error();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		point[i] = init_point(line, i);
		point = ft_realloc(point, i + 1);
		i++;
	}
	free(line);
	line = NULL;
	if (ret > 0 || ret < 0)
		error();
	point[0][0]->sizeline = i;
	return (point);
}
