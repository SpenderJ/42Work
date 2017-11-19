/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:30:48 by juspende          #+#    #+#             */
/*   Updated: 2017/11/12 19:55:30 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"
#include <stdio.h>

void		resolve(char ***tab, int tetriminos_number, t_solution *solution)
{
	int		map_size;
	char	*alphabet;
	char	**map;
	int		count;

	map_size = ft_sqrt(tetriminos_number * 4);
	count = -1;
	while (map_size != 0)
	{
		solution->tetriminos = tetriminos_number;
		solution->map_si = map_size;
		if ((map = malloc(sizeof(char *) * (map_size + 1))) == NULL)
			return;
		fill_map(map, map_size);
		alphabet = ft_strdup("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		alphabet[tetriminos_number] = '\0';
		if (generator(alphabet, tab, map, solution) != NULL)
		{
			if (solution->so[0] != NULL && best_map(solution->so[0], tab, solution) == 0)
				return ;
		}
		free_tab (map);
		free (alphabet);
		++map_size;
	}
}

void		fill_map(char **map, int map_size)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map_size)
	{
		x = -1;
		if ((map[y] = malloc(sizeof(char) * (map_size + 1))) == NULL)
			return ;
		while (++x < map_size)
			map[y][x] = '.';
		map[y][x] = '\0';
	}
	map[y] = NULL;
	return ;
}

void		free_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
}

int			tetri_insert(char **map, char **tetriminos, int x, int y)
{
	int		lon;
	int		lar;

	if ((lon = -1) == -1 && already_exist(tetriminos, map) == 1)
		return (1);
	while (tetriminos[++lon] != NULL)
	{
		if (map[y + lon] == NULL)
			return (1);
		lar = -1;
		while (tetriminos[lon][++lar] != '\0')
		{
			if (map[y + lon][x + lar] == '\0')
				return (1);
			else if (tetriminos[lon][lar] != '.' &&
					map[y + lon][x + lar] != '.')
				return (1);
		}
	}
	lon = -1;
	while (tetriminos[++lon] != NULL && (lar = -1) != -0)
		while (tetriminos[lon][++lar] != '\0')
			if (tetriminos[lon][lar] != '.')
				map[y + lon][x + lar] = tetriminos[lon][lar];
	return (0);
}

int			add_tetriminos(char **map, char **tetriminos, int map_size)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map_size)
	{
		x = -1;
		while (++x < map_size)
		{
			if (tetri_insert(map, tetriminos, x, y) == 0)
			{
				return (0);
			}
		}
	}
	return (1);
}
