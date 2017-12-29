/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:01:17 by juspende          #+#    #+#             */
/*   Updated: 2017/12/29 16:21:20 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static int	int_num(char **argv)
{
	(void)argv;
	return (0);
}

static int	checker(int *a_list, int *b_list, int c_num)
{
	(void)a_list;
	(void)b_list;
	(void)c_num;
	return (0);
}

int			main(int argc, char **argv)
{
	int		c;
	int		t;
	int		*a_list;
	int		*b_list;

	if ((c = 0) == 0 && argc > 2)
		if (((a_list = ft_intnew(argc + 1)) == NULL) ||
				((b_list = ft_intnew(argc + 1)) == NULL))
			return (ft_putsterr(MALLOC_FAILED));
	if ((t = 0) == 0 && argc == 2)
		if (((a_list = ft_intnew(ft_countspace(argv[1]))) == NULL) ||
				((b_list = ft_intnew(ft_countspace(argv[1]))) == NULL))
			return (ft_putsterr(MALLOC_FAILED));
	if (argc == 1 || !argv || argv[0] == NULL)
		return (ft_putsterr(ARGUMENT_ERROR));
	if (argc > 2)
		while (argv[++c] != NULL && ft_isnum(argv[c]))
			a_list[c - 1] = ft_atoi(argv[c]);
	if (argc == 2 && (c = -1) == -1)
		while (argv[1][++c] != '\0' && (a_list[++t] = ft_atoi(&argv[1][c])))
			while (argv[1][c] >= '0' && argv[1][c] <= '9')
				++c;
	argc == 2 ? (c = 1) : c;
	return ((argv[c] && !ft_isnum(argv[c])) ? (ft_putsterr(PARSING_ERROR)) :
			(checker(a_list, b_list, int_num(argv))));
}
