/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 18:36:00 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		d(va_list argp, const char *arg, int *index, t_flag *flag)
{
	intmax_t		tmp;
	int				c;
	int				u;

	(void)arg;
	(void)index;
	c = 1;
	if (flag->h == 0 && flag->ll == 0 && flag->l == 0)
		tmp = va_arg(argp, int);
	else
		length_modif(argp, flag, &tmp);
	if (tmp >= 0 && flag->pos == 1)
		ft_putchar('+', flag);
	if (tmp >= 0 && flag->space == 1)
		ft_putchar(' ', flag);
	u = 0;
	while (c < tmp && ((u = u + 1) == -42))
		c = c * 10;
	if (flag->point != 0)
		while (++u <= flag->point)
			ft_putchar('0', flag);
	else if (flag->larg != 0)
		larg_flag_before(flag);
	ft_putint(tmp, flag);
	larg_flag_after(flag);
	return (0);
}
