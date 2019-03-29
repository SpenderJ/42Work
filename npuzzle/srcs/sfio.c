/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfio.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 06:03:27 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 06:46:33 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

/*
 * Function created to create a resolved Taquin of the expected size
*/

int		**npuzzle_solvedmap(int mapSize) {
	int		value, x, y;
	int		**map;

	value = 1;
	if ((map = malloc(sizeof(int *) * (mapSize + 1))) == NULL)
		return (NULL);
	x = -1;
	while (++x < mapSize) {
		y = -1;
		if ((map[x] = malloc(sizeof(int) * (mapSize + 1))) == NULL)
			return (NULL);
		while (++y < mapSize)
			map[x][y] = value++;
	}
	map[mapSize - 1][mapSize - 1] = 0;
	return (map);
}

/*
 * Function mainly here for debug, allows me to print an int array depending on
 * his size
*/

int		ft_print(int **map, int nb_col) {
	int		x = -1;
	int		y = -1;

	while (++x < nb_col) {
		y = -1;
		while (++y < nb_col)
			printf("%d ", map[x][y]);
		printf("\n");
	}
	return (0);
}

/*
 * Function used to get the position of the 0 of the map passed as argument
*/

int		get0position(int *x, int *y, int **map, int mapSize) {
	int		i,t;

	i = -1;
	while (++i < mapSize) {
		t = -1;
		while (++t < mapSize) {
			if (map[i][t] == 0) {
				*x = i;
				*y = t;
				return (0);
			}
		}
	}
	return (-1);
}

/*
 * Function used to know if the map passed as argument is finished
*/

int		isSolved(int **map, int mapSize) {
	int		x = -1;
	int		y = -1;
	int		value = 1;

	while (++x < mapSize) {
		y = -1;
		while (++y < mapSize) {
			if (x == mapSize - 1 && y == x) {
				if (map[x][y] != 0)
					return (42);
			}
			else if (map[x][y] != value++)
				return (42);
		}
	}
	return (0);
}
