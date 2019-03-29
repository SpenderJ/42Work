/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:22:29 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 06:22:26 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

/*
 * Function to free the map depending on hoz many colums have been allocated
*/

static int	**free_old_map(int **map, int n) {
	while (--n >= 0)
		free(map[n]);
	free(map);
	return (NULL);
}

/*
 * Function to verify that each map is composed of unique characters
*/

static int	**check_map_values(int nb_col, int **map) {
	int		x, y, t_x, t_y;

	t_x = -1;
	while (++t_x < nb_col) {
		t_y = -1;
		while (++t_y < nb_col) {
			x = -1;
			while (++x < nb_col) {
				y = -1;
				while (++y < nb_col) {
					if (x != t_x && y != t_y)
						if (map[x][y] == map[t_x][t_y])
							return (NULL);
				}
			}
		}
	}
	return (map);
}

/*
 * Function to parse the map cleanly, checking the different potentials error
 * And managing comments, filling the map with the values of the sent file.
*/

static int	**map_parser(int nb_col, char *buffer, int i) {
	int		n = -1;
	int		numbers_get = 0;
	int		**map;

	if ((map = malloc(sizeof(int*) * nb_col)) == NULL)
		return (NULL);
	while (++n < nb_col)
		if ((map[n] = malloc(sizeof(int) * nb_col)) == NULL)
			return (free_old_map(map, n));
	n = 0;
	while (buffer[i] != 0) {
		if (buffer[i] == '#')
			while (buffer[++i] != '\n') ;
		else {
			if (n >= nb_col)
				return (free_old_map(map, nb_col));
			numbers_get = 0;
			while (buffer[i] != '\n') {
				if (buffer[i] >= '0' && buffer[i] <= '9')
					map[n][numbers_get++] = ft_atoi(&buffer[i]);
				while (buffer[i] >= '0' && buffer[i] <= '9')
					++i;
				if (buffer[i] == '#')
					while (buffer[i] != '\n')
						++i;
				if (buffer[i] == ' ')
					while (buffer[i] == ' ')
						++i;
				else if (buffer[i] == '\n' || buffer[i] == '\0') {
					if (numbers_get != nb_col)
						return (free_old_map(map, nb_col)); }
				else
					return (free_old_map(map, nb_col)); }
			if (numbers_get != nb_col)
				return (free_old_map(map, nb_col));
			++n; }
		++i; }
	return (check_map_values(nb_col, map));
}

/*
 * Function to parse the content of the file and know the number of column
*/

static int	**map_verifier(char *buffer, int *size) {
	int		i = -1;
	int		error = 0;
	int		nb_col = -1;

	while (buffer[++i] != 0 && nb_col == -1 && error == 0) {
		if (buffer[i] == '#')
			while (buffer[++i] != '\n') ;
		else if (buffer[i] >= '0' && buffer[i] <= '9' && nb_col == -1) {
			nb_col = ft_atoi(&buffer[i]);
			while (buffer[i] >= '0' && buffer[i] <= '9')
				++i;
			if (buffer[i] == '#')
				while (buffer[++i] != '\n') ;
			if (buffer[i] != '\n' && buffer[i] != '\0')
				error = -1; }
		else
			error = -1;
	}
	*size = nb_col;
	return (error == -1 ? NULL : map_parser(nb_col, buffer, i));
}

/*
 * Function to open and get the content of the file sent as an argument
*/

int			**npuzzle_parse(char *filename, int *size) {
	char	*buffer;

	FILE *f = fopen(filename, "r");
	if (f == NULL)
		return (NULL);
	fseek(f, 0, SEEK_END);
	int fsize = ftell(f);
	fseek(f, 0, SEEK_SET);
	if ((buffer = malloc(fsize + 1)) == NULL)
		return (NULL);
	fread(buffer, fsize, 1, f);
	fclose(f);
	buffer[fsize] = 0;
	return map_verifier(buffer, size);
}
