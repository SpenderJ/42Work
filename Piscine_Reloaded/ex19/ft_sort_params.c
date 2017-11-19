/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:35:28 by juspende          #+#    #+#             */
/*   Updated: 2017/11/06 11:35:30 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

int		printtab(char **tab)
{
	int		a;
	int		i;

	i = 1;
	a = 0;
	while (tab[i] != NULL)
	{
		while (tab[i][a] != '\0')
			ft_putchar(tab[i][a++]);
		ft_putchar('\n');
		a = 0;
		i = i + 1;
	}
	return (0);
}

int		mr_swap(int i, char **argv, int argc)
{
	argv[argc + 1] = argv[i];
	argv[i] = argv[i - 1];
	argv[i - 1] = argv[argc + 1];
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		n;

	i = 1;
	while (argv[i] != NULL)
	{
		if (i != 0 && argv[i - 1][0] > argv[i][0])
			i = mr_swap(i, argv, argc);
		else if (i != 0 && argv[i - 1][0] == argv[i][0])
		{
			n = 0;
			while (argv[i - 1][n] == argv[i][n])
				++n;
			if (argv[i - 1][n] > argv[i][n])
				i = mr_swap(i, argv, argc);
			else
				++i;
		}
		else
			++i;
	}
	return (printtab(argv));
}
