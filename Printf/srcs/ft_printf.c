/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:44:26 by juspende          #+#    #+#             */
/*   Updated: 2017/11/17 15:54:06 by juspende         ###   ########.fr       */
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

	*i = -1;
	va_start(argp, list);
	if ((flag = malloc(sizeof(t_flag))) == NULL)
		return (0);
	init_struct(flag);
	while (list[++*i] != '\0')
	{
		if (list[*i] == '%')
		{
			if (arg_parser(argp, &list[*i + 1], i, flag) == -1)
				return (0);
			init_struct(flag);
		}
		else
			ft_putchar(list[*i]);
	}
	return (0);
}

void	init_struct(t_flag *flag)
{
	flag->neg = 0;
	flag->pos = 0;
	flag->space = 0;
	flag->zero = 0;
	flag->diez = 0;
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
	else
		if ((ret = flag_parser(argp, arg, index, flag)) == -1)
			return (-1);
	if (((char)arg[0] >= 'a' && (char)arg[0] <= 'z') || ((char)arg[0] >= 'A' &&
				(char)arg[0] <= 'Z'))
		ret = (*pointer)(argp, arg, index, flag);
	return (ret);
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
		ft_putchar('%');
		return (0);
	}
	else
		return (-1);
	*index = *index + 1;
	return (arg_parser(argp, &arg[1], index, flag));
}
