/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:17:51 by amoinier          #+#    #+#             */
/*   Updated: 2016/02/04 13:20:11 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;

	int			px;
	int			py;

	int			sizeline;
	int			sizecol;
	int			col;
}				t_point;

typedef	struct	s_img
{
	void		*img;
	char		*cimg;
	int			bpp;
	int			sizel;
	int			endn;
}				t_img;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;

	t_img		*img;
	t_point		***point;

	int			movex;
	int			movey;
	float		axex;
	float		axey;
	int			axez;
	int			zoom;
	char		*lol;
	int			col;
}				t_env;

char			**ft_read(char **av);
int				error(void);

int				ft_countcara(char *str);

int				mouse_hook(int button, int x, int y, t_env *init);
int				key_hook(int keycode, t_env *init);
int				expose_hook(t_env *init);

int				bonus_mouse(int sx, int sy, t_env *init);

t_point			***ft_createstruct(char **av);
t_point			**init_point(char *line, int j);

void			draw(t_env *init, t_point ***tab);
void			ft_str_win(t_env *init);

void			line(t_env *init, t_point **tab, int ij[2]);
void			column(t_env *init, t_point ***tab, int ij[2]);

void			pixel_put_image(t_env *init, int x, int y, int color);
void			ft_clear_img(t_env *init);

#endif
