/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 14:01:17 by juspende          #+#    #+#             */
/*   Updated: 2018/01/17 09:15:18 by juspende         ###   ########.fr       */
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

static int	get_command(char *line, int *a_list, int *b_list, int err)
{
	if (ft_strcmp(line, "sa") == 0 && (err = NO_ERROR) == NO_ERROR)
		sa(a_list);
	else if (ft_strcmp(line, "sb") == 0 && (err = NO_ERROR) == NO_ERROR)
		sb(b_list);
	else if (ft_strcmp(line, "ss") == 0 && (err = NO_ERROR) == NO_ERROR)
		ss(a_list, b_list);
	else if (ft_strcmp(line, "pa") == 0 && (err = NO_ERROR) == NO_ERROR)
		pa(a_list, b_list);
	else if (ft_strcmp(line, "pb") == 0 && (err = NO_ERROR) == NO_ERROR)
		pb(a_list, b_list);
	else if (ft_strcmp(line, "ra") == 0 && (err = NO_ERROR) == NO_ERROR)
		ra(a_list);
	else if (ft_strcmp(line, "rb") == 0 && (err = NO_ERROR) == NO_ERROR)
		rb(b_list);
	else if (ft_strcmp(line, "rr") == 0 && (err = NO_ERROR) == NO_ERROR)
		rr(a_list, b_list);
	else if (ft_strcmp(line, "rra") == 0 && (err = NO_ERROR) == NO_ERROR)
		rra(a_list);
	else if (ft_strcmp(line, "rrb") == 0 && (err = NO_ERROR) == NO_ERROR)
		rrb(b_list);
	else if (ft_strcmp(line, "rrr") == 0 && (err = NO_ERROR) == NO_ERROR)
		rrr(a_list, b_list);
	free(line);
	return (err);
}

static int	checker(int *a_list, int *b_list, int c_num, char **argv)
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
	while (get_next_line(1, &line) && line != NULL)
		if (get_command(line, a_list, b_list, WRONG_ARG) == WRONG_ARG)
			return (ft_putsterr(COMMAND_ERROR));
	return (b_list[0] == 0 && ft_intlistsorted(a_list) == 0 ? 
			ft_printf("%s\n", OK_END) :
			ft_printf("%s\n", KO_END));
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
			(checker(a_list, b_list, int_num(argc, argv), argv)));
}
