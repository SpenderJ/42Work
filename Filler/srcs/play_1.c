/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:20:38 by juspende          #+#    #+#             */
/*   Updated: 2017/12/21 15:48:14 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		play_1(t_info *info, t_piece *piece)
{
	fill_info_struct(info);
	ft_get_map(info, piece);
	ft_get_piece(piece);
	dprintf(2, "--------------PIECE: [%c]------------ \n", info->player);
	int i = -1;
	while (piece->piece[++i] != NULL)
		dprintf(2, "%s\n", piece->piece[i]);
	dprintf(2, "---------------MAP:-------------- \n");
	i = -1;
	while (info->map[++i] != NULL)
		dprintf(2, "%s\n", info->map[i]);
	if (piece->x_enemy == FAIL && piece->y_enemy == FAIL && piece->x == FAIL
			&& piece->y == FAIL)
		initialize_algo(info, piece, -1, -1);
	if (algo(info, piece) == 0)
		info->end = SUCCESS;
	dprintf(2, "ATTAQUE SUCCESS NO BOUCLE INF, attaq pos = [%d][%d]\n", info->finaly, info->finalx);
	attack_swap(info);
	send_info(info);
	if (info->end)
		return (SUCCESS);
	return (KEEP_GOING);
}
