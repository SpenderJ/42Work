/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 16:59:30 by juspende          #+#    #+#             */
/*   Updated: 2018/01/08 18:40:58 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	sa(int *a_list)
{
	int		tmp;

	if (a_list[0] <= 1)
		return ;
	tmp = a_list[a_list[0]];
	a_list[a_list[0]] = a_list[a_list[0] - 1];
	a_list[a_list[0] - 1] = tmp;
}

void	sb(int *b_list)
{
	int		tmp;

	if (b_list[0] <= 1)
		return ;
	tmp = b_list[b_list[0]];
	b_list[b_list[0]] = b_list[b_list[0] - 1];
	b_list[b_list[0] - 1] = tmp;
}

void	ss(int *a_list, int *b_list)
{
	sa(a_list);
	sb(b_list);
}
