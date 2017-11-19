/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   previous.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:59:32 by juspende          #+#    #+#             */
/*   Updated: 2017/11/12 18:56:40 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

void		go_check(char *previous, char **map, char ***tetriminos)
{
	int		i;
	int		size;
	int		nb;

	size = -1;
	nb = -1;
	while (tetriminos[++nb] != NULL)
		;
	while (map[++size] != NULL)
		;
	i = ft_strlen(previous);
	if (i == nb)
		while (previous[i - 1] != ('A' + nb - 1) && add_tetriminos(map,
					tetriminos[letter_to_int(previous[i])], size) != 0)
			previous[i] = previous[i] + 1;
	else
	{
		previous[i] = 'A';
		while (previous[i] != 'A' + nb - 1 && (add_tetriminos(map,
						tetriminos[letter_to_int(previous[i])], size) != 0))
		{
			previous[i] = previous[i] + 1;
		}
	}
	return ;
}

int			letter_to_int(char c)
{
	int		i;

	i = 0;
	i = c - 65;
	return (i);
}

int			regen_map(char *previous, char **map, char ***tetriminos)
{
	int		x;
	int		y;
	int		size;

	y = -1;
	while (map[++y] != NULL && (x = -1) == -1)
		while (map[y][++x] != '\0')
			map[y][x] = '.';
	size = y;
	y = -1;
	while (previous[++y] != '\0')
	{
		add_tetriminos(map, tetriminos[(previous[y] - 65)], size);
	}
	return (0);
}

int			go_forward(char **map, char *previous, int nb)
{
	int		n;
	int		i;

	n = -1;
	(void)map;
	while (previous[++n] != '\0')
		;
	if (n != nb)
		return (0);
	if (n != 0)
		--n;
	if (previous[n] != 'A' + nb - 1)
		previous[n] = previous[n] + 1;
	else
	{
		while (previous[--n] == 'A' + nb - 1 && n >= 0)
			;
		if (n == 0)
			return (0);
		previous[n] = previous[n] + 1;
		i = n;
		while (previous[++i] != '\0')
			previous[i] = '\0';
	}
	return (0);
}
