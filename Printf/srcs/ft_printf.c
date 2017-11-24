/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:44:26 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 17:20:09 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		(*letter_parser[26])(va_list, const char*, int*, t_flag*) =
{a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z};

int		ft_printf(const char *restrict list, ...)
{
	int			*i;
	va_list		argp;
	t_flag		*flag;

	if ((i = malloc(sizeof(int) * 2)) == NULL)
		return (-1);
	*i = -1;
	va_start(argp, list);
	if ((flag = malloc(sizeof(t_flag))) == NULL)
		return (0);
	init_struct(flag);
	flag->charn = 0;
	while (list[++*i] != '\0')
	{
		if (list[*i] == '%')
		{
			if (arg_parser(argp, &list[*i + 1], i, flag) == -1)
				return (flag->charn);
			init_struct(flag);
		}
		else
			ft_putchar(list[*i], flag);
	}
	return (flag->charn);
}

void	init_struct(t_flag *flag)
{
	flag->neg = 0;
	flag->pos = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->comma = 0;
	flag->diez = 0;
	flag->point = 0;
	flag->larg = 0;
	return ;
}

int		arg_parser(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		ret;
	int		(*pointer)(va_list, const char*, int*, t_flag*);

	ret = 0;
	if ((char)arg[0] >= 'A' && (char)arg[0] <= 'Z')
		pointer = letter_parser[(int)(arg[0] + 32) - 97];
	else if ((char)arg[0] >= 'a' && (char)arg[0] <= 'z')
		pointer = letter_parser[(int)arg[0] - 97];
	else if (((char)arg[0] >= '1' && (char)arg[0] <= '9') ||
	((char)arg[0] == '.'))
	{
		if ((ret = precision_pars(argp, arg, index, flag)) == -1)
			return (-1);
	}
	else
		if ((ret = flag_parser(argp, arg, index, flag)) == -1)
			return (-1);
	if (((char)arg[0] >= 'a' && (char)arg[0] <= 'z') || ((char)arg[0] >= 'A' &&
				(char)arg[0] <= 'Z'))
		ret = (*pointer)(argp, arg, index, flag);
	*index = *index + 1;
	return (ret);
}

int		precision_pars(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		c;
	int		nbr;

	c = 0;
	if (arg[c] == '.' && (flag->comma = 1) == 1)
	{
		++c;
		flag->point = ft_atoi(&arg[c]);
	}
	else
	{
		nbr = ft_atoi(&arg[c]);
		flag->point = nbr;
	}
	while (arg[c] >= '0' && arg[c] <= '9')
		++c;
	*index = (*index + c) - 1;
	return (arg_parser(argp, &arg[c], index, flag));
}

int		flag_parser(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	check;

	check = (char)arg[0];
	if (check == '-')
		flag->neg = 1;
	else if (check == '+')
		flag->pos = 1;
	else if (check == ' ')
		flag->space = 1;
	else if (check == '0')
		flag->zero = 1;
	else if (check == '#')
		flag->diez = 1;
	else if (check == '%')
	{
		ft_putchar('%', flag);
		return (0);
	}
	else
		return (-1);
	*index = *index + 1;
	return (arg_parser(argp, &arg[1], index, flag));
}
