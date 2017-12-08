/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:20:38 by juspende          #+#    #+#             */
/*   Updated: 2017/12/08 13:59:58 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		play_1(t_info *info, t_piece *piece)
{
	ft_get_map(info, piece);
	ft_get_piece(piece);
	if (algo(info, piece) == 0)
		info->end = SUCCESS;
	dprintf(2, "ATTAQUE SUCCESS NO BOUCLE INF, attaq pos = [%d][%d]\n", info->finaly, info->finalx);
	attack_swap(info);
	send_info(info);
	if (info->end)
		return (SUCCESS);
	return (KEEP_GOING);
}
