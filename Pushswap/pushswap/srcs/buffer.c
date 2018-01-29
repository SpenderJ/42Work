/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:15:08 by juspende          #+#    #+#             */
/*   Updated: 2018/01/29 19:44:28 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int			pushswap2(int *a_list, int *b_list, int c, int n)
{
	int		i;

	while (++n < c - 2 && (i = find_int_position(a_list, n)) != INT_DONT_EXIST)
	{
		i = rr_r(a_list, i);
		if (a_list[0] > 1 && a_list[a_list[0] - 1] == n &&
				ft_publish(SA) != S_ERR)
			sa(a_list);
		while (i == RR && a_list[a_list[0]] != n && ft_publish(RRA) != S_ERR)
			rra(a_list);
		while (i == R && a_list[a_list[0]] != n && ft_publish(RA) != S_ERR)
			ra(a_list);
		if (a_list[a_list[0]] == n && ft_publish(PB) != S_ERR)
			pb(a_list, b_list);
	}
	return (0);
}

static int	clear_add(int *op, int position, int replace, int remove)
{
	int		*new_list;
	int		c;
	int		o;

	c = 0;
	if ((new_list = ft_intnew(op[SUMM] + 2)) == NULL)
		return (ERROR);
	new_list[SUMM] = op[SUMM];
	while (++c < position - 1)
		new_list[c] = op[c];
	if (replace != 0)
		new_list[c] = replace;
	o = c + remove;
	while (++o <= op[SUMM])
		new_list[++c] = op[o];
	new_list[SUMM] = c;
	c = -1;
	while (++c <= new_list[SUMM])
		op[c] = new_list[c];
	free(new_list);
	return (SUCCESS);
}

static int	compare_two_last(int *op, int i)
{
	if (i == 1)
		return (1);
	if (op[i] == PB && op[i - 1] == PA)
		clear_add(op, i, 0, 1);
	else if (op[i] == PA && op[i - 1] == PB)
		clear_add(op, i, 0, 1);
	else if (op[i] == RRA && op[i - 1] == RRB)
		clear_add(op, i, RRR, 1);
	else if (op[i] == RRB && op[i - 1] == RRA)
		clear_add(op, i, RRR, 1);
	else if (op[i] == RA && op[i - 1] == RB)
		clear_add(op, i, RR, 1);
	else if (op[i] == RB && op[i - 1] == RA)
		clear_add(op, i, RR, 1);
	else
		return (1);
	return (0);
}

void		optimize_output(int *op)
{
	int		i;
	int		edit;

	edit = NO_ERROR;
	i = 0;
	while (edit != SUCCESS && (i = op[0] + 1) == op[0] + 1)
	{
		while (edit != ERROR && --i > 0)
		{
			if (compare_two_last(op, i) == 0)
				edit = ERROR;
		}
		if (i == 0)
			edit = SUCCESS;
		else
			edit = NO_ERROR;
	}
	i = 0;
	while (++i <= op[0])
		ft_publish(op[i]);
	free(op);
	return ;
}
