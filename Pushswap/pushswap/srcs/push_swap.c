/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:01:17 by juspende          #+#    #+#             */
/*   Updated: 2018/01/29 19:44:15 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static int	int_num(int argc, char **argv)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (argc > 2)
		while (argv[++i] != NULL)
			if (argv[i] && argv[i][0] != '\0')
				++ret;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			while (argv[1][i] == ' ')
				++i;
			((argv[1][i] >= '0' && argv[1][i] <= '9') || argv[1][i] == '-' ||
			argv[1][i] == '+')
				? (++ret) : ret;
			while ((argv[1][i] >= '0' && argv[1][i] <= '9') || argv[1][i] ==
					'-' || argv[1][i] == '+')
				++i;
		}
	}
	return (ret);
}

static int	pushswap(int *a_list, int *b_list, int c, int n)
{
	int		*op;

	if (ft_intlisttruelysorted(a_list) == SORTED)
		return (free_pushswap(a_list, b_list, SORTED));
	if (a_list[0] > BIG)
		if (((op = ft_intnew((a_list[0] * 2 * 10))) == NULL)
				&& !ft_freeall("%a%a", a_list, b_list))
			return (ft_putsterr(MALLOC_FAILED));
	if ((a_list[0] < SPLIT && !ft_freeall("%a", b_list)) || a_list[0] > BIG)
	{
		return (a_list[0] < SPLIT ? quick_solve(a_list) :
			ds(a_list, b_list, op));
	}
	ft_revint(a_list);
	pushswap2(a_list, b_list, c, n);
	if (a_list[0] == 2 && a_list[1] < a_list[2] && ft_publish(SA) != S_ERR)
		sa(a_list);
	while (b_list[0] != 0 && ft_publish(PA) != S_ERR)
		pa(a_list, b_list);
	return (free_pushswap(a_list, b_list, SORTED));
}

int			rank_alist(int *a_list, int c, int n, int rank)
{
	int	*new_list;

	if (((new_list = ft_intnew(a_list[0] + 2)) == NULL))
		return (ft_putsterr(MALLOC_FAILED));
	new_list[SUMM] = a_list[SUMM];
	while (++c <= a_list[SUMM] && (n = 0) == 0)
		if ((rank = SUMM) == SUMM)
			while (++n <= a_list[SUMM])
				if (a_list[n] < a_list[c])
					new_list[c] = ++rank;
	n = -1;
	while (++n <= new_list[0])
		a_list[n] = new_list[n];
	free(new_list);
	return (RANKED);
}

static int	push_parser(int *a_list, int *b_list, int c_num, char **argv)
{
	int		c;
	int		i;

	a_list[0] = c_num;
	b_list[0] = B_SIZE;
	c = 0;
	while (++c <= c_num && (i = 0) == 0)
		while (++i <= c_num)
			if (((a_list[i] == a_list[c] && c != i) || a_list[i] == A_E) &&
					!ft_freeall("%a%a", a_list, b_list))
				return (ft_putsterr(DOUBLE_ERROR));
	c = 0;
	while (argv[++c] != NULL)
		if (ft_intlimit(argv[c]) == 0 && !ft_freeall("%a%a", a_list, b_list))
			return (ft_putsterr(SIZE_ERROR));
	if (rank_alist(a_list, 0, 0, 0) == ERROR_RANKING && !ft_freeall("%a%a",
				a_list, b_list))
		return (PUSHSWAP_ERROR);
	else
		return (pushswap(a_list, b_list, a_list[0], -1));
}

int			main(int ac, char **av)
{
	int		c;
	int		t;
	int		*a_list;
	int		*b_list;

	if ((c = 0) == 0 && ac != 2)
		if (((a_list = ft_intnew(ac + 2)) == NULL) ||
				((b_list = ft_intnew(ac + 2)) == NULL))
			return (ft_putsterr(MALLOC_FAILED));
	if (((t = 0) == 0) && ac == 2)
		if (((a_list = ft_intnew(ft_countspace(av[1]) + 1)) == NULL) ||
				((b_list = ft_intnew(ft_countspace(av[1]) + 1)) == NULL))
			return (ft_putsterr(MALLOC_FAILED));
	if (ac > 2)
		while (av[++c] != NULL && ft_isnum(av[c]))
			a_list[c] = ft_atoi(av[c]);
	if (ac == 2 && av[1] && ((c = -1) == -1))
		while (av[1][++c] != '\0' && (a_list[++t] = ft_atoi(&av[1][c])) != A_E)
			while (ft_charnum(av[1][c]) && av[1][c + 1])
				++c;
	ac <= 2 ? (c = 1) : c;
	return ((av[c] && !ft_isnum(av[c])) ?
			(ft_putsterr(PARSING_ERROR) && !ft_freeall("%a%a", a_list, b_list))
			: (push_parser(a_list, b_list, int_num(ac, av), av)));
}
