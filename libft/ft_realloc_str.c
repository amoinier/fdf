/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:16:08 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/28 15:31:38 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc_str(char *tab, int size)
{
	char	*tab2;
	int		x;

	x = 0;
	if (!(tab2 = (char *)malloc(sizeof(tab2) * (size + 1))))
		return (NULL);
	while (x != size)
	{
		tab2[x] = tab[x];
		x++;
	}
	free(tab);
	tab = tab2;
	return (tab);
}
