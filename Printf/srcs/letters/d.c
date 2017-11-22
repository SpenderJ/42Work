/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 16:29:15 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		d(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		tmp;
	int		c;
	int		u;

	(void)arg;
	(void)flag;
	(void)index;
	c = 1;
	tmp = va_arg(argp, int);
	if (tmp >= 0 && flag->pos == 1)
		ft_putchar('+', flag);
	if (tmp >= 0 && flag->space == 1)
		ft_putchar(' ', flag);
	u = 0;
	while (c < tmp && ((u = u + 1) == -42))
		c = c * 10;
	++u;
	if (flag->point != 0)
		while (u++ <= flag->point)
			ft_putchar('0', flag);
	ft_putint(tmp, flag);
	return (0);
}
