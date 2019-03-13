/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:22:29 by juspende          #+#    #+#             */
/*   Updated: 2019/03/13 16:11:31 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/npuzzle.h"

/*
 * Function to check the number of row our map contains
*/

static int	**free_old_map(int **map, int n) {
	while (--n >= 0)
		free(map[n]);
	free(map);
	return (NULL);
}

static int	**map_parser(int nb_col, char *buffer, int i) {
	int		**map;
	int		n = -1;
	int		numbers_get = 0;

	if ((map = malloc(sizeof(int*) * 4)) == NULL)
		return (NULL);
	while (++n < nb_col)
		if ((map[n] = malloc(sizeof(int) * 4)) == NULL)
			return (free_old_map(map, n));
	n = 0;
	while (buffer[i] != 0) {
		if (buffer[i] == '#')
			while (buffer[++i] != '\n')
				;
		else {
			if (n >= nb_col)
				return (NULL);
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
						return (NULL); }
				else
					return (NULL);
			}
			if (numbers_get != nb_col)
				return (NULL);
			printf("%d,%d,%d,%d\n", map[n][0], map[n][1], map[n][2], map[n][3]);
			++n;
		}
		++i;
	}
	return (map);
}

static int	**map_verifier(char *buffer)
{
	int		i = -1;
	int		error = 0;
	int		nb_col = -1;

	while (buffer[++i] != 0 && nb_col == -1 && error == 0) {
		if (buffer[i] == '#')
			while (buffer[++i] != '\n')
				;
		else if (buffer[i] >= '0' && buffer[i] <= '9' && nb_col == -1) {
			nb_col = ft_atoi(&buffer[i]);
			while (buffer[i] >= '0' && buffer[i] <= '9')
				++i;
			if (buffer[i] == '#')
				while (buffer[++i] != '\n')
					;
			if (buffer[i] != '\n' && buffer[i] != '\0')
				error = -1; }
		else
			error = -1;
	}
	return (error == -1 ? NULL : map_parser(nb_col, buffer, i));
}

int			**npuzzle_parse(char *filename) {
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
	return (map_verifier(buffer));
}
