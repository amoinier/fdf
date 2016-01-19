/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 17:02:06 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/19 16:22:53 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"

static	char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(tmp, s2);
	free(tmp);
	tmp = NULL;
	return (s1);
}

static	int		ft_stockfile(int const fd, char *tmp[fd])
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	while (!(ft_strchr(tmp[fd], '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp[fd] = ft_strjoin_free(tmp[fd], buf);
	}
	return (ret);
}

static	int		ft_space(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	char			*tt;
	static	char	*tmp[256];

	if (fd < 0 || !line || BUFF_SIZE < 0 || fd > 256)
		return (-1);
	if (!tmp[fd] && (!(tmp[fd] = (char *)malloc(sizeof(tmp[fd]) * (1 + 1)))))
		return (-1);
	if (ft_stockfile(fd, &(*tmp)) < 0)
		return (-1);
	if (tmp[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	*line = ft_strsub(tmp[fd], 0, ft_space(tmp[fd]));
	if (!(tt = (char *)malloc(sizeof(tt) * (ft_strlen(tmp[fd]) + 1))))
		return (-1);
	ft_strcpy(tt, &tmp[fd][ft_space(tmp[fd]) + 1]);
	ft_strclr(tmp[fd]);
	tmp[fd] = ft_strcpy(tmp[fd], tt);
	free(tt);
	return (1);
}
