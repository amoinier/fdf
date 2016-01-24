/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:31:07 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/24 18:24:40 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	nb = 0;
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
