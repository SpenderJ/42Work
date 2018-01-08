/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:56:50 by juspende          #+#    #+#             */
/*   Updated: 2018/01/08 18:08:08 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	rra(int *a_list)
{
	int		tmp;
	int		i;

	i = 0;
	if (a_list[0] <= 1)
		return ;
	tmp = a_list[0];
	while (++i < a_list[0])
		a_list[i] = a_list[i + 1];
	a_list[1] = tmp;
}

void	rrb(int *b_list)
{
	int		tmp;
	int		i;

	i = 0;
	if (b_list[0] <= 1)
		return ;
	tmp = b_list[0];
	while (++i < b_list[0])
		b_list[i] = b_list[i + 1];
	b_list[1] = tmp;
}

void	rrr(int *a_list, int *b_list)
{
	rra(a_list);
	rrb(b_list);
}
