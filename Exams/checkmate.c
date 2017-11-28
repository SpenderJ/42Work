/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:13:55 by exam              #+#    #+#             */
/*   Updated: 2017/11/21 15:10:15 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		c;

	c = 0;
	if (!str)
		return (c);
	while (str[c] != '\0')
		++c;
	return (c);
}

int		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	return (0);
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

int		pawn(char **tab, int x, int y)
{
	if (y <= 1)
		return (0);
	if (x >= 1 && tab[y - 1][x - 1] == 'K')
		return (1);
	if (tab[y - 1][x + 1] == 'K')
		return (1);
	return (0);
}

int		piece_checker(char c)
{
	if (c == 'P' || c == 'B' || c == 'R' || c == 'Q')
		return (-1);
	return (0);
}

int		bishop(char **tab, int x, int y)
{
	int		xt;
	int		yt;

	xt = x;
	yt = y;
	while (++xt >= 0 && ++yt >= 1 && tab[yt] != NULL && tab[yt][xt] != '\0' && piece_checker(tab[yt][xt]) == 0)
		if (tab[yt][xt] == 'K')
			return (1);
	xt = x;
	yt = y;
	while (--xt >= 0 && ++yt >= 1 && tab[yt] != NULL && tab[yt][xt] != '\0' && piece_checker(tab[yt][xt]) == 0)
		if (tab[yt][xt] == 'K')
			return (1);
	xt = x;
	yt = y;
	while (++xt >= 0 && --yt >= 1 && tab[yt] != NULL && tab[yt][xt] != '\0' && piece_checker(tab[yt][xt]) == 0)
		if (tab[yt][xt] == 'K')
			return (1);
	xt = x;
	yt = y;
	while (--xt >= 0 && --yt >= 1 && tab[yt] != NULL && tab[yt][xt] != '\0' && piece_checker(tab[yt][xt]) == 0)
		if (tab[yt][xt] == 'K')
			return (1);
	return (0);
}

int		rook(char **tab, int x, int y)
{
	int		xt;
	int		yt;

	xt = x;
	yt = y;
	while (xt >= 0 && ++yt >= 1 && tab[yt] != NULL && tab[yt][xt] != '\0' && piece_checker(tab[yt][xt]) == 0)
		if (tab[yt][xt] == 'K')
			return (1);
	xt = x;
	yt = y;
	while (++xt >= 0 && yt >= 1 && tab[yt] != NULL && tab[yt][xt] != '\0' && piece_checker(tab[yt][xt]) == 0)
		if (tab[yt][xt] == 'K')
			return (1);
	xt = x;
	yt = y;
	while (xt >= 0 && --yt >= 1 && tab[yt] != NULL && tab[yt][xt] != '\0' && piece_checker(tab[yt][xt]) == 0)
		if (tab[yt][xt] == 'K')
			return (1);
	xt = x;
	yt = y;
	while (--xt >= 0 && yt >= 1 && tab[yt] != NULL && tab[yt][xt] != '\0' && piece_checker(tab[yt][xt]) == 0)
		if (tab[yt][xt] == 'K')
			return (1);
	return (0);
}

int		queen(char **tab, int x, int y)
{
	if (bishop(tab, x, y) == 1)
		return (1);
	if (rook(tab, x, y) == 1)
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;
	int		size;
	int		king;
	int		x;
	int		y;

	i = 0;
	x = -1;
	y = 0;
	king = 0;
	//
	// DEBUT GESTION D ERREUR DE MAP
	//
	if (argc == 1)
		return (ft_putchar('\n'));
	size = ft_strlen(argv[1]);
	while (argv[++i] != NULL)
		if (ft_strlen(argv[i]) != size)
			return (ft_putstr("Fail\n"));
	if (argc - 1 != size)
		return (ft_putstr("Fail\n"));
	while (argv[++y] != NULL && (x = -1) == -1)
		while (argv[y][++x] != '\0')
			if (argv[y][x] == 'K')
				++king;
	if (king != 1)
		return (ft_putstr("Fail\n"));
	//
	//ALL GESTION D ERREUR FINIE
	//
	y = 0;
	while (argv[++y] != NULL && (x = -1) == -1)
	{
		while (argv[y][++x] != '\0')
		{
			if (argv[y][x] == 'P' && pawn(argv, x, y) == 1)
				return (ft_putstr("Success\n"));
			else if (argv[y][x] == 'B' && bishop(argv, x, y) == 1)
				return (ft_putstr("Success\n"));
			else if (argv[y][x] == 'R' && rook(argv, x, y) == 1)
				return (ft_putstr("Success\n"));
			else if (argv[y][x] == 'Q' && queen(argv, x, y) == 1)
				return (ft_putstr("Success\n"));
		}
	}
	return (ft_putstr("Fail\n"));
}

