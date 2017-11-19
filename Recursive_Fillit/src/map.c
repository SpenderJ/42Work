/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:36:26 by juspende          #+#    #+#             */
/*   Updated: 2017/11/14 10:38:44 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

void	free_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
		ft_memdel((void **)&(map->array[i]));
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

void	print_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
	}
}

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = -1;
	while (++i < size)
	{
		map->array[i] = ft_strnew(size);
		j = -1;
		while (++j < size)
			map->array[i][j] = '.';
	}
	return (map);
}

int		place(t_tetris *tetris, t_map *map, int x, int y)
{
	int i;
	int j;

	i = -1;
	while (++i < tetris->l && (j = -1) == -1)
		while (++j < tetris->h)
			if (tetris->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
	set_piece(tetris, map, point_new(x, y), tetris->value);
	return (1);
}

void	set_piece(t_tetris *tetris, t_map *map, t_point *point, char c)
{
	int i;
	int j;

	i = -1;
	while (++i < tetris->l && (j = -1) == -1)
		while (++j < tetris->h)
			if (tetris->pos[j][i] == '#')
				map->array[point->y + j][point->x + i] = c;
	ft_memdel((void **)&point);
}
