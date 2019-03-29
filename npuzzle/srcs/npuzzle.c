/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:15:36 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 03:56:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

static int	ft_print(int **map, int nb_col) {
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
 * In case of error the program is returning -1, otherwise, it will return
 * 0 in case of good work
*/

int			main(int argc, char **argv) {
	int		**map;
	int		size;

	if (!argc || ! argv || argc != 2 || !argv[1])
		return (handle_error(NO_FILE_INPUT));
	if ((map = npuzzle_parse(argv[1], &size)) == NULL)
		return (handle_error(ILLEGAL_MAP));
	ft_print(map, size);
	return (0);
}
