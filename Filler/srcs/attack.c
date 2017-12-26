/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:30:10 by juspende          #+#    #+#             */
/*   Updated: 2017/12/26 13:09:26 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int		algo_down_left(t_info *info, t_piece *piece, int i, int j)
{
	while (--i > 0 && (j = -1) == -1)
		while (++j < info->xmap)
			if (try_value(piece, info, i, j) == 1 && (info->finalx = j) == j &&
					(info->finaly = i) == i)
				return (ATTACK_SUCCESS_TIME_TO_LAUNCH_THE_NEW_MAP);
	return (KEEP_GOING);
}

static int		algo_up_right(t_info *info, t_piece *piece, int i, int j)
{
	while (++i < info->ymap && (j = info->xmap + 1) == info->xmap + 1)
		while (--j > 0)
			if (try_value(piece, info, i, j) == 1 && (info->finalx = j) == j &&
					(info->finaly = i) == i)
				return (ATTACK_SUCCESS_TIME_TO_LAUNCH_THE_NEW_MAP);
	return (KEEP_GOING);
}

static int		algo_down_right(t_info *info, t_piece *piece, int i, int j)
{
	while (--i > 0 && (j = (info->xmap + 1)) == info->xmap + 1)
		while (--j > 0)
			if (try_value(piece, info, i, j) == 1 && (info->finalx = j) == j &&
					(info->finaly = i) == i)
				return (ATTACK_SUCCESS_TIME_TO_LAUNCH_THE_NEW_MAP);
	return (KEEP_GOING);
}

static int		algo_up_left(t_info *info, t_piece *piece, int i, int j)
{
	while (++i < info->ymap && (j = -1) == -1)
		while (++j < info->xmap)
			if (try_value(piece, info, i, j) == 1 && (info->finalx = j) == j &&
					(info->finaly = i) == i)
				return (ATTACK_SUCCESS_TIME_TO_LAUNCH_THE_NEW_MAP);
	return (KEEP_GOING);
}

int				algo(t_info *info, t_piece *piece)
{
//	dprintf(2, "Attaque == %d\n", info->attack);
	if (info->attack == UPLEFT)
		return (algo_up_left(info, piece, -1, 0));
	else if (info->attack == DOWNRIGHT)
		return (algo_down_right(info, piece, info->ymap + 1, 0));
	else if (info->attack == UPRIGHT)
		return (algo_up_right(info, piece, -1, 0));
	else if (info->attack == DOWNLEFT)
		return (algo_down_left(info, piece, info->ymap + 1, 0));
	else
		return (KEEP_GOING);
}
