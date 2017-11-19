/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   succes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:09:29 by juspende          #+#    #+#             */
/*   Updated: 2017/11/12 18:53:27 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		already_exist(char **tetriminos, char **map)
{
	int		i;
	char	c;
	int		n;

	i = 0;
	while (tetriminos[0][i] == '.')
		++i;
	n = -1;
	c = tetriminos[0][i];
	i = -1;
	while (map[++n] != NULL)
	{
		i = -1;
		while (map[n][++i] != '\0')
			if (map[n][i] == c)
				return (1);
	}
	return (0);
}

int		str_check(char *str, char c)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == c)
			return (-1);
	return (0);
}

int		previous_check(char *previous, int tetriminos_number)
{
	int		i;

	i = 0;
	while (previous[++i] != '\0')
	{
		if (previous[i] != 'A' + tetriminos_number - 1)
			return (1);
	}
	if (i != tetriminos_number)
		return (1);
	return (0);
}

int		success(char **map, int tetriminos_number)
{
	int		x;
	int		y;
	int		c;
	char	*str;

	if ((str = ft_strnew(27)) == NULL)
		return (-1);
	y = -1;
	c = 0;
	while (map[++y] != NULL && (x = -1) == -1)
		while (map[y][++x] != '\0')
			if (map[y][x] != '.' && str_check(str, map[y][x]) == 0)
				str[c++] = map[y][x];
	x = -1;
	while (str[++x] != '\0')
		;
	free(str);
	if (x != tetriminos_number)
		return (1);
	return (0);
}

int		best_map(char *str, char ***tab, t_solution *solution)
{
	int		i;
	char	**map;
	int		c;

	i = 0;
	c = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
		++i;
	if ((map = malloc(sizeof(char *) * (i + 1))) == NULL)
		return (-1);
	fill_map(map, solution->map_si);
	regen_map(str, map, tab);
	ft_print_words_tables(map);
	return (0);
}
