/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:20:38 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 15:11:18 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		play_1(t_info *info, t_piece *piece)
{
	int		i;

	i = 0;
	(void)piece;
	ft_get_map(info, piece);
	ft_get_piece(piece);
	dprintf(2, "#DEBUG SECTION \n\n\n\n");
	while (piece->piece[i])
		dprintf(2, "%s\n", piece->piece[i++]);
	i = 0;
	while (info->map[i])
		dprintf(2, "%s\n", info->map[i++]);
	dprintf(2, "#END OF DEBUG\n\n\n\n");
	if (info->end)
		return (1);
	return (0);
}
