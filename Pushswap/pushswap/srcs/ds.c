/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ds.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:48:54 by juspende          #+#    #+#             */
/*   Updated: 2018/01/26 16:56:10 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	parse_again_with_medians(int *a_list, int *b_list)
{
	int		*med_table;
	int		init;
	int		sorted;

	sorted = a_list[1];
	med_table = ft_intnew(b_list[0]);
	med_table[MED_NUM] = MED_NUM;
	med_table[1] = ft_intmax(b_list);
	++med_table[MED_NUM];
	while (b_list[0] >= 2)
	{
		++med_table[MED_NUM];
		med_table[med_table[MED_NUM]] = (ft_intmax(b_list) + ft_intmin(b_list)) / 2;
		init = b_list[1];
		while (b_list[b_list[0]] != init)
		{
			if (b_list[b_list[0]] > med_table[med_table[MED_NUM]] &&
					ft_publish(PA) != S_ERR)
				pa(a_list, b_list);
			else if (ft_publish(RB) != S_ERR)
				rb(b_list);
		}
	}
	--med_table[MED_NUM];
	if (b_list[0] == 1 && ft_publish(PA) != S_ERR && ft_publish(RA) != S_ERR)
	{
		pa(a_list, b_list);
		ra(a_list);
		--med_table[MED_NUM];
		med_table[med_table[MED_NUM] + 1] = 0;
	}
	while (med_table[MED_NUM] > 1)
	{
		while (a_list[a_list[0]] <= med_table[med_table[MED_NUM]] && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
		if (b_list[0] < LOW_SIZE_TO_SORT)
			selective_sort(a_list, b_list);
		else
			parse_again_with_medians(a_list, b_list);
		--med_table[MED_NUM];
		med_table[med_table[MED_NUM] + 1] = 0;
	}
	return (SORTED);
}

int		selective_sort(int *a_list, int *b_list)
{
	int		min;
	int		c;

	while (b_list[0] != EMPTY)
	{
		c = 0;
		min = 1;
		while (++c <= b_list[0])
			b_list[c] < b_list[min] ? (min = c) : c;
		c = rr_r(b_list, c);
		min = b_list[min];
		while (c == RR && b_list[b_list[0]] != min && ft_publish(RRB) != S_ERR)
			rrb(b_list);
		while (c == R && b_list[b_list[0]] != min && ft_publish(RB) != S_ERR)
			rb(b_list);
		if (b_list[b_list[0]] == min && ft_publish(PA) != S_ERR &&
				ft_publish(RA) != S_ERR)
		{
			pa(a_list, b_list);
			ra(a_list);
		}
	}
	return (SORTED);
}

int			ds(int *a_list, int *b_list)
{
	int		summ;
	int		init;

	ft_revint(a_list);
	summ = a_list[0];
	init = a_list[1];
	while (a_list[a_list[0]] != init)
	{
		if (a_list[a_list[0]] < (summ / 2) && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
		else if (ft_publish(RA) != S_ERR)
			ra(a_list);
	}
	while (b_list[0] != EMPTY && ft_publish(PA) != S_ERR)
		pa(a_list, b_list);
	return (ds2(a_list, b_list, summ));
}

int			ds2(int *a_list, int *b_list, int summ)
{
	while (a_list[a_list[0]] < summ / 2)
	{
		while (a_list[a_list[0]] < (summ / 2) && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
		if (b_list[0] < LOW_SIZE_TO_SORT)
			selective_sort(a_list, b_list);
		else
			parse_again_with_medians(a_list, b_list);
	}
	while(a_list[a_list[0]] > summ / 2)
	{
		while (a_list[a_list[0]] >= (summ / 2) && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
		if (b_list[0] < LOW_SIZE_TO_SORT)
			selective_sort(a_list, b_list);
		else
			parse_again_with_medians(a_list, b_list);
	}
	ft_printint(a_list);
	return (SORTED);
}
