/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:25:54 by exam              #+#    #+#             */
/*   Updated: 2017/07/14 18:54:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
	return (0);
}

int		put_buf(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}

int		main(int argc, char **argv)
{
	char	buffer[4096];
	int		c_buf;
	int		c_str;
	int		n;

	buffer[0] = '\0';
	if (argc != 3)
		return (ft_putchar('\n'));
	n = 0;
	while (++n < 3)
	{
		c_str = -1;
		while (argv[n][++c_str] != '\0')
		{
			c_buf = 0;
			while (buffer[c_buf] != '\0' && buffer[c_buf] != argv[n][c_str])
				++c_buf;
			if (buffer[c_buf] == '\0')
			{
				buffer[c_buf] = argv[n][c_str];
				buffer[c_buf + 1] = '\0';
			}
		}
	}
	return (put_buf(buffer));
}
