/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:40:48 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/22 16:01:08 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	char	**ft_dstrcpy(char **str, int i, char *line)
{
	char	**str2;
	int		x;

	x = 0;
	if (!(str2 = (char **)malloc(sizeof(str2) * (i + 1))))
		return (NULL);
	while (x < i)
	{
		str2[x] = ft_strdup(str[x]);
		x++;
	}
	str2[x] = ft_strdup(line);
	return (str2);
}

char			**ft_read(char **av)
{
	int		fd;
	int		i;
	char	*line;
	char	**str;

	i = 0;
	if (!(str = (char **)malloc(sizeof(str) * 2)))
		return (NULL);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		str = ft_dstrcpy(str, i, line);
		i++;
	}
	str = ft_dstrcpy(str, i, line);
	return (str);
}
