/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_attack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:49:24 by juspende          #+#    #+#             */
/*   Updated: 2017/12/09 09:43:44 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	attack_swap(t_info *info)
{
	if (info->attack == UPLEFT)
		info->attack = DOWNLEFT;
	else if (info->attack == DOWNRIGHT)
		info->attack = UPRIGHT;
	else if (info->attack == UPRIGHT)
		info->attack = DOWNRIGHT;
	else if (info->attack == DOWNLEFT)
		info->attack = UPLEFT;
}
