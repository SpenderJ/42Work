/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:46:21 by juspende          #+#    #+#             */
/*   Updated: 2019/03/20 16:37:29 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "t_point.h"

/*
 * main is not my function, sorry for ugly code
*/

static void		ft_putc(char c) {
	write(1, &c, 1);
}

static void		print_tab(char **tab) {
	int x = -1;
	int y = -1;

	while (tab[++x] != NULL) {
		y = -1;
		while (tab[x][++y] != '\0') {
			write(1, &tab[x][y], 1);
		}
		write(1, "\n", 1);
	}
}

static char		**make_area(char **zone) {
	char	**map;
	int		y = -1;
	int		ymax;
	int		x = -1;
	int		xmax;

	while (zone[++y] != NULL)
		;
	while (zone[0][++x] != '\0')
		;
	if ((map = malloc(sizeof(char *) * (y + 1))) == NULL)
		return (NULL);
	ymax = y;
	xmax = x;
	y = -1;
	while (++y < ymax) {
		x = -1;
		if ((map[y] = malloc(sizeof(char) * (xmax + 1))) == NULL)
			return (NULL);
		while (zone[y][++x] != '\0')
			map[y][x] = zone[y][x];
		map[y][x] = '\0';
	}
	map[y] = NULL;
	return (map);
}

static void		rec(char **tab, int x, int y, char toColor, t_point size) {
	if (tab[y][x] != toColor)
		return ;
	if (tab[y][x] == toColor)
		tab[y][x] = 'F';
	if (x >= 1 && y >= 0 && tab[y][x-1] == toColor)
		rec(tab, x-1, y, toColor, size);
	if (y >= 1 && x >= 0 && tab[y-1][x] == toColor)
		rec(tab, x, y-1, toColor, size);
	if (x < size.x - 1 && y < size.y && tab[y][x+1] == toColor)
		rec(tab, x+1, y, toColor, size);
	if (y < size.y - 1 && x < size.x && tab[y+1][x] == toColor)
		rec(tab, x, y+1, toColor, size);
	return ;
}

static void		flood_fill(char **tab, t_point size, t_point begin) {
	char	toColor = tab[begin.y][begin.x];
	int		x;
	int		y;

	x = begin.x;
	y = begin.y;
	if (tab[y][x] == toColor)
		tab[y][x] = 'F';
	if (x >= 1 && y >= 0 && tab[y][x-1] == toColor)
		rec(tab, x-1, y, toColor, size);
	if (y >= 1 && x >= 0 && tab[y-1][x] == toColor)
		rec(tab, x, y-1, toColor, size);
	if (x < size.x - 1 && y < size.y && tab[y][x+1] == toColor)
		rec(tab, x+1, y, toColor, size);
	if (y < size.y - 1 && x < size.x && tab[y+1][x] == toColor)
		rec(tab, x, y+1, toColor, size);
}

int				main(void)
{
	char **area;
	t_point size = { 8, 5 };
	t_point begin = { 5, 0 };
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001"
	};
	
	area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	ft_putc('\n');
	print_tab(area);
	return (0);
}
