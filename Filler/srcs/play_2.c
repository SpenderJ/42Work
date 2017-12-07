/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:20:38 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 18:44:56 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		play_2(t_info *info, t_piece *piece)
{
	ft_get_map(info, piece);
	ft_get_piece(piece);
	if (info->end)
		return (SUCCESS);
	return (KEEP_GOING);
}
