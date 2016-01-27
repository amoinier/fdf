/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:52:46 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/27 15:21:24 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_val(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static	char	*ft_nbr(int n, int val, int i, char *tab)
{
	int	j;
	int	power;

	j = 0;
	while (j < val)
	{
		power = val - (j) - 1;
		tab[i] = 48 + (n / (ft_power(10, power)) % 10);
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}

char			*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*tab;
	int		val;

	i = 0;
	j = 0;
	val = ft_val(n);
	if (n < 0)
		val++;
	if (!(tab = (char *)malloc(sizeof(char) * (val + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		tab[0] = '-';
		i++;
		n = -n;
		val--;
	}
	tab = ft_nbr(n, val, i, tab);
	return (tab);
}
