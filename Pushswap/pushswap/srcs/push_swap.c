/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:01:17 by juspende          #+#    #+#             */
/*   Updated: 2018/01/11 16:51:55 by juspende         ###   ########.fr       */
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
			((argv[1][i] >= '0' && argv[1][i] <= '9') || argv[1][i] == '-')
				? (++ret) : ret;
			while ((argv[1][i] >= '0' && argv[1][i] <= '9') || argv[1][i] ==
					'-')
				++i;
		}
	}
	return (ret);
}

static int	pushswap(int *a_list, int *b_list)
{
	return (SORTED);
}

static int	rank_alist(int *a_list, int c, int n, int rank)
{
	int	*new_list;

	if (((new_list = ft_intnew(a_list[0] + 2)) == NULL) ||
			(new_list[SUMM] = a_list[SUMM]) < 0)
		return (ft_putsterr(MALLOC_FAILED));
	while (a_list[++c] < a_list[SUMM] && (n = 0) == 0)
		if ((rank = SUMM) == SUMM)
			while (a_list[++n] < a_list[SUMM])
				if (a_list[n] > a_list[c] && ++rank)
					new_list[c] = rank;
	free(a_list);
	a_list = new_list;
	return (RANKED);
}

static int	push_parser(int *a_list, int *b_list, int c_num, char **argv)
{
	char	*line;
	int		c;
	int		i;

	a_list[0] = c_num;
	b_list[0] = B_SIZE;
	c = 0;
	ft_revint(a_list);
	while (++c < c_num && (i = 0) == 0)
		while (++i < c_num)
			if (a_list[i] == a_list[c] && c != i)
				return (ft_putsterr(DOUBLE_ERROR));
	c = 0;
	while (argv[++c] != NULL)
		if (ft_intlimit(argv[c]) == 0)
			return (ft_putsterr(SIZE_ERROR));
	return (SORTED);
}

int			main(int argc, char **argv)
{
	int		c;
	int		t;
	int		*a_list;
	int		*b_list;

	if (argv && argv[1] && ft_strcmp(argv[1], "-h") == 0)
		return (ft_printf("%s%s%s\n", HELP_1, HELP_2, HELP_3));
	if ((c = 0) == 0 && argc != 2)
		if (((a_list = ft_intnew(argc + 2)) == NULL) ||
				((b_list = ft_intnew(argc + 2)) == NULL))
			return (ft_putsterr(MALLOC_FAILED));
	if ((t = 0) == 0 && argc == 2)
		if (((a_list = ft_intnew(ft_countspace(argv[1]) + 1)) == NULL) ||
				((b_list = ft_intnew(ft_countspace(argv[1]) + 1)) == NULL))
			return (ft_putsterr(MALLOC_FAILED));
	if (argc > 2)
		while (argv[++c] != NULL && ft_isnum(argv[c]))
			a_list[c] = ft_atoi(argv[c]);
	if (argc == 2 && (c = -1) == -1)
		while (argv[1][++c] != '\0' && (a_list[++t] = ft_atoi(&argv[1][c])))
			while (argv[1][c] >= '0' && argv[1][c] <= '9')
				++c;
	argc <= 2 ? c = 1 : c;
	return ((argv[c] && !ft_isnum(argv[c])) ? (ft_putsterr(PARSING_ERROR)) :
			(push_parser(a_list, b_list, int_num(argc, argv), argv)));
}
