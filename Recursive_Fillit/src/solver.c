/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:35:53 by juspende          #+#    #+#             */
/*   Updated: 2017/11/14 11:39:37 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../libft/libft.h"
#include "../includes/fillit.h"

/*
** READ ME TUTORIAL RECURSIVE FILLIT
** GO TO BLANK
** While(we got a map)
** Put [New Tetri]
** If (Last Tetri)
** return 1
** If (Recursiv Func == 1)
** Return 1
** else
** Remove last tetri
** While [Next Case] != empty
** return 0
*/

int		solve_map(t_map *map, t_list *list)
{
	int			x;
	int			y;
	t_tetris	*tetris;

	if (list == NULL)
		return (1);
	y = -1;
	tetris = (t_tetris *)(list->content);
	while (++y < map->size - tetris->h + 1 && (x = -1) == -1)
	{
		while (++x < map->size - tetris->l + 1)
		{
			if (place(tetris, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetris, map, point_new(x, y), '.');
			}
		}
	}
	return (0);
}

int		high_sqrt(int n)
{
	int		size;

	size = 2;
	while (size * size < n)
		++size;
	return (size);
}

t_map	*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = high_sqrt(ft_lstcount(list) * 4);
	map = map_new(size);
	while (!solve_map(map, list))
	{
		++size;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}
