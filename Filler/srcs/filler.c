/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:03:34 by juspende          #+#    #+#             */
/*   Updated: 2017/12/21 14:59:32 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	init_struct(t_info *info, t_piece *piece)
{
	info->player = 0;
	info->ymap = 0;
	info->player = 'N';
	info->xmap = 0;
	info->letter = 0;
	info->end = 0;
	info->attack = 0;
	piece->ypiece = 0;
	piece->xpiece = 0;
	piece->x_enemy = 0;
	piece->y_enemy = 0;
	piece->y = 0;
	piece->x = 0;
}

int			main(void)
{
	t_info	info;
	t_piece	piece;

	init_struct(&info, &piece);
//	if (info.player == 1)
	while (play_1(&info, &piece) != 0)
		;
//	else if (info.player == 2)
//		while (play_2(&info, &piece) != 0)
//			;
//	else
//		ft_putsterrr(WRONG_INPUT);
	return (0);
}
