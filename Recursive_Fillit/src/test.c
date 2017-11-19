/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:36:39 by juspende          #+#    #+#             */
/*   Updated: 2017/11/14 11:23:12 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

int		test_file(char *str)
{
	int		c;
	int		tet;
	int		l;

	c = 0;
	tet = 0;
	while (str[c])
	{
		l = 0;
		if ((c = line(str, c, tet, l)) < 0)
			return (1);
		if ((str[c] && str[c] != '\n') || (!str[c + 1] && str[c]))
			return (1);
		++c;
		++tet;
	}
	return (0);
}

int		line(char *str, int c, int tet, int l)
{
	int		co;
	int		i;

	i = 0;
	co = 0;
	while (l++ % 5 < 4 && str[c])
	{
		while (str[c] && (c - tet) % 5 < 4)
		{
			if (!(str[c] == '#' || str[c] == '.'))
				return (-1);
			if (str[c] == '#')
				++i;
			if (co < 0 || i > 4)
				return (-1);
			co += test_co(str, c);
			++c;
		}
		if (str[c] != '\n')
			return (-1);
		++c;
	}
	if (co < 6 || l != 5)
		return (-1);
	return (c);
}

int		test_co(char *str, int c)
{
	int		co;

	co = 0;
	if (str[c] == '#')
	{
		if (str[c + 1] == '#')
			++co;
		if (str[c - 1] == '#')
			++co;
		if (str[c + 5] == '#')
			++co;
		if (str[c - 5] == '#')
			++co;
	}
	return (co);
}

t_list	*read_tetris(int fd)
{
	char	*buf;
	char	*str;
	int		c;

	c = 0;
	buf = ft_strnew(22);
	str = ft_strnew(1);
	while ((c = read(fd, buf, 21)))
	{
		if (c == -1)
		{
			ft_strdel(&buf);
			ft_strdel(&str);
			return (NULL);
		}
		str = ft_strjoin(str, buf);
		ft_bzero(buf, 21);
	}
	ft_strdel(&buf);
	if (str == NULL || test_file(str))
	{
		ft_strdel(&str);
		return (NULL);
	}
	return (tetris_read(str));
}
