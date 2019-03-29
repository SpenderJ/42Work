/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hamming.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 04:09:52 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 06:22:24 by juspende         ###   ########.fr       */
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

int		hamming_distance(int **map, int mapSize) {
	int		**solvedMap;
	int		distance = 0;

	if ((solvedMap = npuzzle_solvedmap(mapSize)) == NULL)
		return (free_map(map, mapSize, -1));
	return distance;
}
