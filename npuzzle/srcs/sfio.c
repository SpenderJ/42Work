/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfio.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 06:03:27 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 06:15:08 by juspende         ###   ########.fr       */
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
