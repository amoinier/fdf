/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:31:07 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/20 17:02:04 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_dstrcpy(char **str, int i, char *line)
{
	char	**str2;
	int	x;

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

char	**ft_read(char **av)
{
	int	fd;
	int	i;
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

int		ft_countcara(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == 32 && str[i])
			i++;
		while (str[i] != 32 && str[i])
			i++;
		j++;
	}
	if (str[i - 1] == 32)
		j--;
	return (j);
}

int		ft_longline(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (j < ft_countcara(str[i]))
			j = ft_countcara(str[i]);
		i++;
	}
	return (j);
}

int		ft_countnbline(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_countbn(char *s)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			nb++;
		}
		i++;
	}
	return (nb);
}
