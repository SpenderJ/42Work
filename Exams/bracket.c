/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 10:01:25 by exam              #+#    #+#             */
/*   Updated: 2018/01/23 10:28:35 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		ft_putstr(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
		ft_putchar(str[i]);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		n;
	int		b;
	char	buffer[4096];

	n = 0;
	if (argc == 1)
		return (ft_putchar('\n'));
	while (argv[++n] && (i = -1) == -1)
	{
		b = 0;
		buffer[b] = '\0';
		while (argv[n][++i] && b != -2)
		{
			if (argv[n][i] == 40 || argv[n][i] == 91 || argv[n][i] == 123)
				buffer[b++] = argv[n][i];
			else if (argv[n][i] == 41 || argv[n][i] == 93 || argv[n][i] == 125)
			{
				if (b == 0 && (b = -2) == -2)
					ft_putstr("Error\n");
				else if (argv[n][i] == 41 && buffer[b - 1] != 40 && (b = -2) == -2)
					ft_putstr("Error\n");
				else if (argv[n][i] == 93 && buffer[b - 1] != 91 && (b = -2) == -2)
					ft_putstr("Error\n");
				else if (argv[n][i] == 125 && buffer[b - 1] != 123 && (b = -2) == -2)
					ft_putstr("Error\n");
				else
					buffer[--b] = '\0';
			}
		}
		if (b == 0)
			ft_putstr("OK\n");
		else if (b != -2)
			ft_putstr("Error\n");
	}
	return (0);
}
