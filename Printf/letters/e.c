/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/18 17:07:25 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		e(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		i;
	double	tmp;

	(void)index;
	(void)arg;
	(void)flag;
	i = 0;
	tmp = va_arg(argp, double);
	if (tmp < 0)
	{
		ft_putchar('-');
		tmp = -tmp;
	}
	while (tmp > 10 && ++i)
		tmp = tmp / 10;
	ft_putdouble(tmp, -1);
	if (i > 0)
	{
		if ((char)arg[0] == 'e')
			ft_putstr("e+");
		else
			ft_putstr("E+");
		ft_putint(i);
	}
	return (0);
}
