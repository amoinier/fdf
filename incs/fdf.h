/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:17:51 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/15 11:03:52 by amoinier         ###   ########.fr       */
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

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		px;
	int		py;
	int		sizeline;
	int		sizecol;
	int		movex;
	int		movey;
}				t_point;

char		*ft_read(char **av);
int			ft_countcara(char *str);
int			ft_countnbline(char **s);
int			ft_longline(char **str);
int			*ft_toint(char **str, int size);

int			mouse_hook(int button, int x, int y, t_env *init);
int			key_hook(int keycode);
int			expose_hook(t_env *init);

t_point		***ft_init_t_point(int nbline, char **str);
t_point		*ft_pointnew(int x, int y, int z);
t_point		***ft_createstruct(int *line, int *coln, char **av);

void		draw(void *mlx, void *win, int col);
void		draw42(t_env *init, t_point ***tab);
void		drawline(t_env *init, t_point ***tab);
void		drawcol(t_env *init, t_point ***tab);

#endif
