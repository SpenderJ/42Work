/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 12:46:53 by jebossue          #+#    #+#             */
/*   Updated: 2017/11/01 12:46:55 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*buf_transfer_n(t_buf *lst, char **line)
{
	int i;

	i = 0;
	while (i < lst->nb && lst->buf[i] != '\n')
		i++;
	if ((*line = ft_nrealloc(*line, (lst->line_len + i) + 1,
					lst->line_len)) == NULL)
		return (NULL);
	ft_memcpy((*line + lst->line_len), lst->buf, i);
	(*line)[lst->line_len + i] = '\0';
	lst->line_len += i;
	ft_memmove(lst->buf, ft_memchr(lst->buf, '\n', lst->nb) + 1,
			BUFF_SIZE - (i + 1));
	lst->nb -= (i + 1);
	return (*line);
}

static char	*buf_transfer_nb(t_buf *lst, char **line)
{
	if ((*line = ft_nrealloc(*line, (lst->line_len + lst->nb) + 1,
					lst->line_len)) == NULL)
		return (NULL);
	ft_memcpy((*line + lst->line_len), lst->buf, lst->nb);
	(*line)[lst->line_len + lst->nb] = '\0';
	lst->line_len += lst->nb;
	return (*line);
}

static int	get_next_line_r(t_buf *lst, char **line)
{
	int			tmp;

	if (!lst)
		return (-1);
	if ((ft_memchr(lst->buf, '\n', lst->nb)))
	{
		if ((*line = buf_transfer_n(lst, line)) == NULL)
			return (-1);
		lst->line_len = 0;
		return (1);
	}
	if ((*line = buf_transfer_nb(lst, line)) == NULL)
		return (-1);
	tmp = lst->nb;
	lst->nb = read(lst->fd, lst->buf, BUFF_SIZE);
	if (tmp == 0 && lst->nb == 0)
		return (0);
	else if (lst->nb < 0)
		return (-1);
	else if (lst->nb > 0)
		get_next_line_r(lst, line);
	lst->line_len = 0;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_buf	lst = {.nb = 0, .line_len = 0};

	lst.fd = fd;
	if (lst.nb < 0)
		lst.nb = 0;
	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	return (get_next_line_r(&lst, line));
}
