/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:20:38 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 19:52:42 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		play_1(t_info *info, t_piece *piece)
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
