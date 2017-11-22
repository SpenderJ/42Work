/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 15:48:56 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		e(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		i;
	double	tmp;

	(void)index;
	if ((tmp = va_arg(argp, double)) >= 0 && flag->pos == 1)
		ft_putchar('+');
	else if (tmp >= 0 && flag->space == 1)
		ft_putchar(' ');
	if ((i = 0) == 0 && tmp < 0)
		if ((tmp = -tmp) > 0)
			ft_putchar('-');
	while (tmp > 10 && ++i)
		tmp = tmp / 10;
	(flag->comma != 0 ? ft_putdouble(tmp, flag->point) : ft_putdouble(tmp, -1));
	if (i > 0)
	{
		if ((char)arg[0] == 'e')
			ft_putstr("e+");
		else
			ft_putstr("E+");
		if (i < 10)
			ft_putchar('0');
		ft_putint(i);
	}
	return (0);
}
