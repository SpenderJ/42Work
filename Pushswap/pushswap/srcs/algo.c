/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 10:46:00 by juspende          #+#    #+#             */
/*   Updated: 2018/01/15 17:07:13 by juspende         ###   ########.fr       */
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
		return (RR);
	else
		return (R);
}

int		ft_publish(int command)
{
	if (command == SA)
		return (ft_printf("%b2sa\n%b0"));
	else if (command == SB)
		return (ft_printf("%b2sb\n%b0"));
	else if (command == SS)
		return (ft_printf("%b3ss\n%b0"));
	else if (command == PA)
		return (ft_printf("%b4pa\n%b0"));
	else if (command == PB)
		return (ft_printf("%b4pb\n%b0"));
	else if (command == RA)
		return (ft_printf("%b5ra\n%b0"));
	else if (command == RB)
		return (ft_printf("%b5rb\n%b0"));
	else if (command == RR)
		return (ft_printf("%b3rr\n%b0"));
	else if (command == RRA)
		return (ft_printf("%b6rra\n%b0"));
	else if (command == RRB)
		return (ft_printf("%b6rrb\n%b0"));
	else if (command == RRR)
		return (ft_printf("%b3rrr\n%b0"));
	return (ERROR_RANKING);
}

int		quick_solve(int *a_list)
{
	int		n;
	int		i;

	n = 0;
	ft_printint(a_list);
	if ((i = find_int_position(a_list, n)) == -84)
		return (ft_putsterr(UNKNOWN_BUG));
	if (a_list[SUMM + 1] != a_list[0] && ft_publish(SA) != ERROR_RANKING)
		sa(a_list);
	if (ft_intlistsorted(a_list) == SORTED)
		return (SORTED);
	if (a_list[1] == SUMM)
	{
		if (ft_intlistsorted(a_list) != SORTED && a_list[2] == SUMM + 1)
			if (ft_publish(RA) != ERROR_RANKING)
				ft_publish(SA);
		if (ft_intlistsorted(a_list) != SORTED && a_list[2] == a_list[SUMM] - 1)
			if (ft_publish(RRA) != ERROR_RANKING)
				ft_publish(SA);
	}
	else
		if (ft_publish(RA) != ERROR_RANKING)
			if (ft_intlistsorted(a_list) != SORTED)
				if (ft_publish(SA) != ERROR_RANKING)
					return (SORTED);
	return (SORTED);
}