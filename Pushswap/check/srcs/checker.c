/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:01:17 by juspende          #+#    #+#             */
/*   Updated: 2017/12/29 18:55:01 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

static int	checker(int *a_list, int *b_list, int c_num, char **argv)
{
	char	*line;
	int		c;
	int		i;

	c = -1;
	(void)b_list;
	while (++c < c_num && (i = -1) == -1)
		while (++i < c_num)
			if (a_list[i] == a_list[c] && c != i)
				return (ft_putsterr(DOUBLE_ERROR));
	c = 0;
	while (argv[++c] != NULL)
		if (ft_intlimit(argv[c]) == 0)
			return (ft_putsterr(SIZE_ERROR));
	while (get_next_line(1, &line) && line != NULL)
		;
	return (0);
}

int			main(int argc, char **argv)
{
	int		c;
	int		t;
	int		*a_list;
	int		*b_list;

	if ((c = 0) == 0 && argc != 2)
		if (((a_list = ft_intnew(argc + 1)) == NULL) ||
				((b_list = ft_intnew(argc + 1)) == NULL))
			return (ft_putsterr(MALLOC_FAILED));
	if ((t = 0) == 0 && argc == 2)
		if (((a_list = ft_intnew(ft_countspace(argv[1]))) == NULL) ||
				((b_list = ft_intnew(ft_countspace(argv[1]))) == NULL))
			return (ft_putsterr(MALLOC_FAILED));
	if (argc > 2)
		while (argv[++c] != NULL && ft_isnum(argv[c]))
			a_list[c - 1] = ft_atoi(argv[c]);
	if (argc == 2 && (c = -1) == -1)
		while (argv[1][++c] != '\0' && (a_list[++t] = ft_atoi(&argv[1][c])))
			while (argv[1][c] >= '0' && argv[1][c] <= '9')
				++c;
	argc <= 2 ? c = 1 : c;
	return ((argv[c] && !ft_isnum(argv[c])) ? (ft_putsterr(PARSING_ERROR)) :
			(checker(a_list, b_list, int_num(argc, argv), argv)));
}
