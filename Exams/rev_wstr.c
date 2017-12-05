/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 19:31:05 by exam              #+#    #+#             */
/*   Updated: 2017/07/14 19:48:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	print_world(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t'\
			&& str[i] != '\n')
		ft_putchar(str[i++]);
}

int		main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc != 2)
		return (ft_putchar('\n'));
	while (argv[1][i] != '\0')
		++i;
	i = i - 1;
	while (i > 0)
	{
		while (i > 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'\
					|| argv[1][i] == '\n'))
			i = i - 1;
		while (i > 0 && argv[1][i] != ' ' && argv[1][i] != '\t'\
				&& argv[1][i] != '\n')
			i = i - 1;
		if (i > 0)
			i++;
		print_world(&argv[1][i--]);
		if (i > 0)
			ft_putchar(' ');
	}
	ft_putchar('\n');
	return (0);
}
