/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 18:36:55 by juspende          #+#    #+#             */
/*   Updated: 2018/01/28 14:07:17 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../includes/get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	static char		*c[OPEN_MAX + 1];
	char			buffer[BUFF_SIZE + 1];
	char			*tmp;
	ssize_t			b;
	int				endl;

	if (fd < 0 || (!c[fd] && !(c[fd] = ft_strnew(1))) || !line)
		return (-1);
	while (!ftt_strchr(c[fd], '\n') && (b = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[b] = '\0';
		tmp = c[fd];
		c[fd] = ft_strjoin(c[fd], buffer);
		ft_strdel(&tmp);
	}
	if ((b == -1 || !*(tmp = c[fd])) && !ft_freeall("%b", c[fd]))
		return (b == -1 ? -1 : 0);
	if ((endl = (ftt_strchr(c[fd], '\n') > 0)))
		*line = ft_strsub(c[fd], 0, ftt_strchr(c[fd], '\n') - c[fd]);
	else
		*line = ft_strdup(c[fd]);
	c[fd] = ft_strsub(c[fd], (unsigned int)(ft_strrlen(*line) + endl),
		(size_t)(ft_strrlen(c[fd]) - (ft_strrlen(*line) + endl)));
	ft_strdel(&tmp);
	return (c[fd] != NULL);
}
