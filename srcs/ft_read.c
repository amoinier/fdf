/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:31:07 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/19 12:08:59 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_read(char **av)
{
	char	*str;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		fd;

	str = ft_strnew(1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (NULL);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
	}
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

int		*ft_toint(char **str, int size)
{
	int	i;
	int	*tab;

	i = 0;
	tab = (int *)malloc(sizeof(tab) * (size + 1));
	while (i < size)
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	return (tab);
}
