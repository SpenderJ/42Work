/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 16:48:27 by juspende          #+#    #+#             */
/*   Updated: 2017/12/21 17:10:48 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	check_mate(t_piece *piece, t_info *info, int y, int x)
{
	char	c;

	(void)piece;
	c = info->letter;
	if (info->map[y][x] == c || info->map[y][x] == c + 32)
		return (SUCCESS);
	return (FAIL);
}

static int ft_occuped(char **map, int y, int x, char c)
{
	if (map[y][x] == c)
		return (SUCCESS);
	else if (map[y][x] == MAJ + c)
		return (SUCCESS);
	return (FAIL);
}

static int	check_value(t_piece *piece, t_info *info, int i, int j)
{
	int		over;
	int		y;
	int		x;

	over = 0;
	y = -1;
	while (++y < piece->ypiece && (x = -1) == -1)
	{
		while (++x < piece->xpiece)
		{
			if (piece->piece[y][x] == FREE_SPACE &&
					check_mate(piece, info, y + i, x + j) == SUCCESS)
				++over;
			dprintf(2, "Over = %d\n", over);
			if ((ft_occuped(info->map, y + i, x + j, info->letter_enemy) == 1)
					&& piece->piece[y][x] == FREE_SPACE)
				return (FAIL);
		}
	}
	return ((over == 1) ? 1 : 0);
}

void		initialize_algo(t_info *info, t_piece *piece, int i, int j)
{
	while (++i < info->ymap && (j = -1) == -1)
		while (++j < info->xmap)
			if (info->map[i][j] == P1 || info->map[i][j] == P2)
				set_values(i, j, info, piece);
	info->attack = (piece->y_enemy > piece->y ? 1 : 0);
}

int		try_value(t_piece *piece, t_info *info, int i, int j)
{
	if (i + piece->ypiece > info->ymap)
		return (FAIL);
	else if (j + piece->xpiece > info->xmap)
		return (FAIL);
	else
		return (check_value(piece, info, i, j));
}
