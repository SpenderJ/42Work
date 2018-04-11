/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:25:43 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/04 11:26:14 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void		ft_new_data(char **old_buff, char *tmp, char *buff)
{
	tmp = ft_strdup(*old_buff);
	ft_memdel((void **)old_buff);
	*old_buff = ft_strjoin(tmp, buff);
	ft_memdel((void **)&tmp);
}

static int			ft_data_checker(char **old_buff, char **line)
{
	char			*tmp;

	tmp = ft_strchr(*old_buff, '\n');
	if (tmp)
	{
		*line = ft_strsub(*old_buff, 0, tmp - *old_buff);
		ft_memmove(*old_buff, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

static	int			ft_buffer(int fd, char **old_buff, char **line)
{
	char			*buff;
	char			*tmp;
	int				ret;

	if (!(buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	buff[BUFF_SIZE] = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		tmp = NULL;
		if (*old_buff)
			ft_new_data(old_buff, tmp, buff);
		else
			*old_buff = ft_strdup(buff);
		if (ft_data_checker(old_buff, line))
		{
			ft_memdel((void **)&buff);
			return (1);
		}
	}
	ft_memdel((void **)&buff);
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static	char	*old_buff[OPEN_MAX];
	char			*check_error_fd;
	int				ret;

	if (!(check_error_fd = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	if (!line || fd < 0 || fd > OPEN_MAX || read(fd, check_error_fd, 0) < 0)
	{
		ft_memdel((void **)&check_error_fd);
		if (line != NULL)
			*line = NULL;
		return (-1);
	}
	ft_memdel((void **)&check_error_fd);
	if (old_buff[fd] && ft_data_checker(&old_buff[fd], line))
		return (1);
	if ((ret = ft_buffer(fd, &old_buff[fd], line)) != 0)
		return (ret);
	if (old_buff[fd] == NULL || old_buff[fd][0] == '\0')
		return (0);
	*line = old_buff[fd];
	old_buff[fd] = NULL;
	return (1);
}
