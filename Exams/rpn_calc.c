/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:03:23 by exam              #+#    #+#             */
/*   Updated: 2018/02/06 10:33:22 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef ERROR
#  define ERROR "Error"
# endif

# ifndef OPT_ERROR
#  define OPT_ERROR 84
# endif

# ifndef ADD
#  define ADD 1
# endif

# ifndef SUB
#  define SUB 2
# endif

# ifndef MUL
#  define MUL 3
# endif

# ifndef DIV
#  define DIV 4
# endif

# ifndef MOD
#  define MOD 5
# endif

static int	check_opt(char c)
{
	if (c == '+')
		return (ADD);
	else if (c == '-')
		return (SUB);
	else if (c == '*')
		return (MUL);
	else if (c == '/')
		return (DIV);
	else if (c == '%')
		return (MOD);
	return (OPT_ERROR);
}

int			main(int argc, char **argv)
{
	int		i;
	int		res;
	int		buffer[4096];
	int		b_pos;
	int		opt;

	i = 0;
	res = 0;
	buffer[0] = 0;
	b_pos = 0;
	if (argc != 2 || !argv[1])
		return (printf("%s\n", ERROR));
	while (argv[1][i] != '\0')
	{
		res = 0;
		opt = OPT_ERROR;
		while (argv[1][i] != '\0' && (argv[1][i] == ' ' || argv[1][i] == '\t'))
			++i;
		if (argv[1][i] != '\0' && check_opt(argv[1][i]) != OPT_ERROR)
			opt = check_opt(argv[1][i++]);
		else if (argv[1][i] != '\0' && (argv[1][i] == '-' || (argv[1][i] >= '0' && argv[1][i] <= '9')))
		{
			buffer[b_pos++] = atoi(&argv[1][i]);
			while (argv[1][i] != '\0' && (argv[1][i] == '-' || (argv[1][i] >= '0' && argv[1][i] <= '9')))
				++i;
			if (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
				return (printf("%s\n", ERROR));
		}
		else
			return (printf("%s\n", ERROR));
		if (opt != OPT_ERROR)
		{
			if (b_pos < 2)
				return (printf("%s\n", ERROR));
			if (opt == ADD)
				res = buffer[b_pos - 2] + buffer[b_pos - 1];
			else if (opt == SUB)
				res = buffer[b_pos - 2] - buffer[b_pos - 1];
			else if (opt == MUL)
				res = buffer[b_pos - 2] * buffer[b_pos - 1];
			else if ((opt == DIV || opt == MOD) && buffer[b_pos - 1] == 0)
				return (printf("%s\n", ERROR));
			else if (opt == DIV)
				res = buffer[b_pos - 2] / buffer[b_pos - 1];
			else if (opt == MOD)
				res = buffer[b_pos - 2] % buffer[b_pos - 1];
			--b_pos;
			buffer[b_pos] = 0;
			buffer[b_pos - 1] = res;
		}
	}
	if (b_pos > 1)
		return (printf("%s ivi\n", ERROR));
	else
		return (printf("%d\n", buffer[b_pos - 1]));
}
