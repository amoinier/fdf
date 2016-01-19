/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:17:51 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/19 16:58:33 by amoinier         ###   ########.fr       */
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
# include "get_next_line.h"

# define BUFF_SIZE 500

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;

	int		px;
	int		py;

	int		sizeline;
	int		sizecol;
}				t_point;

typedef	struct	s_img
{
	void	*img;
	char	*cimg;
	int		bpp;
	int		sizel;
	int		endian;
}				t_img;

typedef struct  s_env
{
	void    *mlx;
	void    *win;
	int		width;
	int		height;

	t_img	*img;
	
	t_point	***point;

	int		movex;
	int		movey;
	int		axex;
	int		axey;
	int		axez;
	int		zoom;
}               t_env;

char		**ft_read(char **av);
int			ft_countbn(char *s);
int			ft_countcara(char *str);
int			ft_countnbline(char **s);
int			ft_longline(char **str);

int			mouse_hook(int button, int x, int y, t_env *init);
int			key_hook(int keycode, t_env *init);
int			expose_hook(t_env *init);

t_point		***ft_init_t_point(int nbline, char **str);
t_point		*ft_pointnew(int x, int y, int z);
t_point		***ft_createstruct(int *line, int *coln, char **av);

void		draw(void *mlx, void *win, int col);
void		draw42(t_env *init, t_point ***tab, int col);
void		drawline(t_env *init, t_point ***tab, int col);
void		drawcol(t_env *init, t_point ***tab, int col);

#endif
