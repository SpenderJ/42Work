/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 15:46:52 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		f(va_list argp, const char *arg, int *index, t_flag *flag)
{
	double	tmp;

	(void)arg;
	(void)index;
	(void)flag;
	tmp = va_arg(argp, double);
	if (tmp >= 0 && flag->pos == 1)
		ft_putchar('+', flag);
	if (tmp >= 0 && flag->space == 1)
		ft_putchar(' ', flag);
	larg_flag_before(flag);
	if (flag->comma != 0)
		ft_putstr(ft_itoa_double(tmp, flag->point), flag);
	else
		ft_putstr(ft_itoa_double(tmp, -1), flag);
	larg_flag_after(flag);
	return (0);
}
