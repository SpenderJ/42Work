/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hamming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 04:09:52 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 08:14:57 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

/*
 * Function to free the map allocated thanks to her size, and then returning
 * the expected value passed as third argument
*/

static int	free_map(int **map, int size, int ret) {
	int		x = -1;

	while (++x < size)
		free(map[x]);
	free(map);
	return (ret);
}

/*
 * Function used to calculate how many case are well filled the higher the score
 * is the best it is. Best score matches mapSize * mapSize
*/

static int	*get_weight(int **map, int **solvedMap, int mapSize) {
	int		x, y;
	int		x0, y0;
	int		*dir;
	int		up, down, left, right;
	int		weight, tmp;
	int		c_int;

	if (get0position(&x0, &y0, map, mapSize) == -1)
		return (NULL);
	
	if ((dir = malloc(sizeof(int) * 5)) == NULL)
		return (NULL);
	/* 
	 * SWAP
	*/

	up = -1;
	down = -1;
	left = -1;
	right = -1;

	c_int = 0;

	if (x0 < mapSize - 1 && (weight = 0) == 0)
	{
		x = -1;
		tmp = map[x0][y0];
		map[x0][y0] = map[x0 + 1][y0];
		map[x0 + 1][y0] = tmp;

		while (++x < mapSize && (y = -1) == -1)
			while (++y < mapSize)
				if (map[x][y] == solvedMap[x][y])
					++weight;
		dir[c_int] = weight;
		up = dir[c_int++];
		tmp = map[x0][y0];
		map[x0][y0] = map[x0 + 1][y0];
		map[x0 + 1][y0] = tmp;
	}

	/*
	 * SWAP
	*/

	if (y0 < mapSize - 1 && (weight = 0) == 0)
	{
		x = -1;
		tmp = map[x0][y0];
		map[x0][y0] = map[x0][y0 + 1];
		map[x0][y0 + 1] = tmp;

		while (++x < mapSize && (y = -1) == -1)
			while (++y < mapSize)
				if (map[x][y] == solvedMap[x][y])
					++weight;
		dir[c_int] = weight;
		right = dir[c_int++];
		tmp = map[x0][y0];
		map[x0][y0] = map[x0][y0 + 1];
		map[x0][y0 + 1] = tmp;
	}

	/*
	 * SWAP
	*/

	if (x0 >= 1 && (weight = 0) == 0)
	{
		x = -1;
		tmp = map[x0][y0];
		map[x0][y0] = map[x0 - 1][y0];
		map[x0 - 1][y0] = tmp;

		while (++x < mapSize && (y = -1) == -1)
			while (++y < mapSize)
				if (map[x][y] == solvedMap[x][y])
					++weight;
		dir[c_int] = weight;
		down = dir[c_int++];
		tmp = map[x0][y0];
		map[x0][y0] = map[x0 - 1][y0];
		map[x0 - 1][y0] = tmp;
	}

	/*
	 * SWAP
	*/

	if (y0 >= 1 && (weight = 0) == 0)
	{
		x = -1;
		tmp = map[x0][y0];
		map[x0][y0] = map[x0][y0 - 1];
		map[x0][y0 - 1] = tmp;

		while (++x < mapSize && (y = -1) == -1)
			while (++y < mapSize)
				if (map[x][y] == solvedMap[x][y])
					++weight;
		dir[c_int] = weight;
		left = dir[c_int++];
		tmp = map[x0][y0];
		map[x0][y0] = map[x0][y0 - 1];
		map[x0][y0 - 1] = tmp;
	}

	c_int--;
	int c = 1;
	while (c <= c_int) {
		if (dir[c - 1] > dir[c]) {
			tmp = dir[c];
			dir[c] = dir[c- 1];
			dir[c - 1]= tmp;
			c = 1;
		}
		else
			++c;
	}
	c = 0;
	while (c <= c_int) {
		if (up != -1 && up == dir[c] && (up = -1) == -1)
			dir[c++] = 1;
		else if (right != -1 && right == dir[c] && (right = -1) == -1)
			dir[c++] = 2;
		else if (down != -1 && down == dir[c] && (down = -1) == -1)
			dir[c++] = 3;
		else if (left != -1 && left == dir[c] && (left = -1) == -1)
			dir[c++] = 4;
	}
	return (dir);
}

/*
 * Function launching the hamming algorithmn to calculate the number of moves
 * needed
*/

int		hamming_distance(int **map, int mapSize) {
	int		**solvedMap;
	int		distance = 0;
	char	**queue;
	int		q;

	q = -1;

/*
 * Allocating different parts needed
*/

	if ((queue = malloc(sizeof(char *) * ((mapSize + 1) * mapSize))) == NULL)
		return (free_map(map, mapSize, -1));
	queue[0] = NULL;
	if ((solvedMap = npuzzle_solvedmap(mapSize)) == NULL)
		return (free_map(map, mapSize, -1));


	/*
	 * We go for some debug
	*/

	if (isSolved(map, mapSize)) {
		get_weight(map, solvedMap, mapSize);
	}

	return distance;
}
