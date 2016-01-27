/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoinier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 17:02:06 by amoinier          #+#    #+#             */
/*   Updated: 2016/01/27 15:57:40 by amoinier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	if (!(s1 = ft_strjoin(tmp, s2)))
		return (NULL);
	free(tmp);
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

static	int		ft_line(int const fd, char *tmp[fd], char **line)
{
	int		spc;
	char	*tt;

	spc = ft_space(tmp[fd]);
	*line = ft_strsub(tmp[fd], 0, spc);
	if (!(tt = (char *)malloc(sizeof(tt) * (ft_strlen(tmp[fd]) + 1))))
		return (-1);
	ft_strcpy(tt, &tmp[fd][spc + 1]);
	ft_strclr(tmp[fd]);
	tmp[fd] = ft_strcpy(tmp[fd], tt);
	free(tt);
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static	char	*tmp[256];

	if (fd < 0 || !line || BUFF_SIZE < 0 || fd > 256)
		return (-1);
	if (!tmp[fd] && (!(tmp[fd] = ft_strnew(2))))
		return (-1);
	if (ft_stockfile(fd, &(*tmp)) < 0)
		return (-1);
	if (tmp[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (ft_line(fd, tmp, line) < 0)
		return (-1);
	return (1);
}
