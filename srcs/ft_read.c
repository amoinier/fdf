/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/04 12:11:57 by amoinier         ###   ########.fr       */
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
	p = NULL;
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
	if (!(point = (t_point ***)malloc(sizeof(point))))
		error();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		point[i] = init_point(line, i);
		point = ft_realloc(point, i + 1);
		free(line);
		line = NULL;
		i++;
	}
	if (ret != 0 || i == 0)
		error();
	free(line);
	line = NULL;
	point[0][0]->sizeline = i;
	return (point);
}
