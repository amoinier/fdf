/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:17:51 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/08 20:44:17 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

typedef struct	point
{
	int		x;
	int		y;
	int		z;
}				t_point;

char		*ft_read(char **av);
int			ft_countcara(char *str);
int			ft_countnbline(char **s);
int			*ft_toint(char **str, int size);

void		ft_printi(int **tab);

#endif
