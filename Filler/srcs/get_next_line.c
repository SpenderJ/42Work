/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 13:25:05 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 18:42:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	int				ret;
	char			*rest;
	char			buffer[BUFF_SIZE + 1];
	static char		*s[2147483648];

	if (!line || fd < 0 || !(s[fd] = !s[fd] ? ft_strnew(1) : s[fd]))
		return (-1);
	while (!ft_strchr(s[fd], '\n') && (ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		rest = s[fd];
		buffer[ret] = '\0';
		s[fd] = ft_strjoin(rest, buffer);
		free(rest);
	}
	if (ret == -1)
		return (-1);
	*line = (ft_strchr(s[fd], '\n') ? ft_strsub(s[fd], 0,
				ft_strchr(s[fd], '\n') - s[fd]) : ft_strdup(s[fd]));
	if (ft_strchr((rest = s[fd]), '\n'))
		s[fd] = ft_strsub(s[fd], ft_strchr(s[fd], '\n') - s[fd] + 1,
				ft_strlen(s[fd]));
	else
		ft_strdel(&s[fd]);
	free(rest);
	return (!s[fd] && ft_strlen(*line) == 0 ? 0 : 1);
}
