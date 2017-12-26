/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:20:38 by juspende          #+#    #+#             */
/*   Updated: 2017/12/26 13:10:08 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		play_2(t_info *info, t_piece *piece)
{
	ft_get_map(info, piece);
	ft_get_piece(piece);
	if (algo(info, piece) == 0)
		info->end = SUCCESS;
	attack_swap(info);
	send_info(info);
	if (info->end)
		return (SUCCESS);
	return (KEEP_GOING);
}
