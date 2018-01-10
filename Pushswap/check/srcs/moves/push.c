/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 17:17:19 by juspende          #+#    #+#             */
/*   Updated: 2018/01/10 17:06:27 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker.h"

void	pa(int *a_list, int *b_list)
{
	int		tmp;

	if (b_list[0] == 0)
		return ;
	tmp = b_list[b_list[0]];
	b_list[b_list[0]] = 0;
	--b_list[0];
	++a_list[0];
	a_list[a_list[0]] = tmp;
}

void	pb(int *a_list, int *b_list)
{
	int		tmp;

	if (a_list[0] == 0)
		return ;
	tmp = a_list[a_list[0]];
	a_list[a_list[0]] = 0;
	--a_list[0];
	++b_list[0];
	b_list[b_list[0]] = tmp;
}
