/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:49:15 by juspende          #+#    #+#             */
/*   Updated: 2018/01/08 19:05:54 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	ra(int *a_list)
{
	int		tmp;
	int		i;

	if (a_list[0] <= 1)
		return ;
	i = a_list[0] + 1;
	tmp = a_list[a_list[0]];
	while (--i > 1)
		a_list[i] = a_list[i - 1];
	a_list[1] = tmp;
}

void	rb(int *b_list)
{
	int		tmp;
	int		i;

	if (b_list[0] <= 1)
		return ;
	i = b_list[0] + 1;
	tmp = b_list[b_list[0]];
	while (--i > 1)
		b_list[i] = b_list[i - 1];
	b_list[1] = tmp;
}

void	rr(int *a_list, int *b_list)
{
	ra(a_list);
	rb(b_list);
}
