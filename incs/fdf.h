/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <amoinier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:17:51 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/25 19:24:20 by amoinier         ###   ########.fr       */
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

# define BUFF_SIZE 2048

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
	int		endn;
}				t_img;
typedef	struct	s_env
{
	void	*mlx;
	void	*win;
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
}				t_env;

char		**ft_read(char **av);

int			ft_countbn(char *s);
int			ft_countcara(char *str);

int			mouse_hook(int button, int x, int y, t_env *init);
int			key_hook(int keycode, t_env *init);
int			expose_hook(t_env *init);

t_point		*ft_pointnew(int x, int y, int z, int coln);
t_point		***ft_createstruct(char **av);
t_point		**init_point(char *line, int j);

void		draw(t_env *init, t_point ***tab, int col);
void		line(t_env *init, t_point **tab, int j, int col);
void		column(t_env *init, t_point ***tab, int ij[2], int col);

void		pixel_put_image(t_env *init, int x, int y, int color);

int			error(void);

#endif
