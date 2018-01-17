/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:46:00 by juspende          #+#    #+#             */
/*   Updated: 2018/01/17 09:42:56 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int		list_sorted(int *a_list, int *b_list)
{
	if (b_list[0] != 0)
		return (ERROR_RANKING);
	if (ft_intlistsorted(a_list) != SORTED)
		return (ERROR_RANKING);
	return (RANKED);
}

int		find_int_position(int *list, int tofind)
{
	int		i;

	i = 0;
	while (++i <= list[0])
		if (list[i] == tofind)
			return (i);
	return (INT_DONT_EXIST);
}

int		rr_r(int *a_list, int pos)
{
	if (pos > a_list[0] / 2)
		return (R);
	else
		return (RR);
}

int		ft_publish(int command)
{
	if (command == SA)
		return (ft_printf("sa\n"));
	else if (command == SB)
		return (ft_printf("sb\n"));
	else if (command == SS)
		return (ft_printf("ss\n"));
	else if (command == PA)
		return (ft_printf("pa\n"));
	else if (command == PB)
		return (ft_printf("pb\n"));
	else if (command == RA)
		return (ft_printf("ra\n"));
	else if (command == RB)
		return (ft_printf("rb\n"));
	else if (command == RR)
		return (ft_printf("rr\n"));
	else if (command == RRA)
		return (ft_printf("rra\n"));
	else if (command == RRB)
		return (ft_printf("rrb\n"));
	else if (command == RRR)
		return (ft_printf("rrr\n"));
	return (ERROR_RANKING);
}

int		quick_solve(int *a_list)
{
	if (a_list[SUMM + 1] == SUMM && a_list[2] == a_list[0] - 1 &&
			ft_publish(RRA) != ERROR_RANKING)
		ft_publish(SA);
	else if (a_list[SUMM + 1] == SUMM + 1 && a_list[2] == a_list[0] - 1 &&
			ft_publish(RRA) != ERROR_RANKING)
		;
	else if (a_list[SUMM + 1] == SUMM + 1 && a_list[2] == SUMM &&
			ft_publish(SA) != ERROR_RANKING)
		;
	else if (a_list[SUMM + 1] == a_list[0] - 1 && a_list[2] == SUMM &&
			ft_publish(RRA) != ERROR_RANKING)
		ft_publish(RRA);
	else if (a_list[SUMM + 1] == a_list[0] - 1 && a_list[2] == SUMM + 1 &&
			ft_publish(SA) != ERROR_RANKING && ft_publish(RA) != ERROR_RANKING)
		ft_publish(RA);
	free(a_list);
	return (SORTED);
}
