/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 18:57:29 by exam              #+#    #+#             */
/*   Updated: 2017/07/14 19:10:40 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		print_pgcd(int pgcd)
{
	printf("%d\n", pgcd);
	return (0);
}

int		main(int argc, char **argv)
{
	int		nb1;
	int		nb2;
	int		pgcd;

	if (argc != 3)
		return (ft_putchar('\n'));
	nb1 = atoi(argv[1]);
	nb2 = atoi(argv[2]);
	if (nb1 < nb2)
		pgcd = nb1;
	else
		pgcd = nb2;
	while (pgcd > 0)
	{
		if ((nb1 % pgcd == 0) && (nb2 % pgcd == 0))
			return (print_pgcd(pgcd));
		pgcd = pgcd - 1;
	}
	return (ft_putchar('\n'));
}
