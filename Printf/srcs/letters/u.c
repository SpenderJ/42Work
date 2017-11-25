/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 15:48:38 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		u(va_list argp, const char *arg, int *index, t_flag *flag)
{
	unsigned int	tmp;


	(void)arg;
	(void)index;
	(void)flag;
	larg_flag_before(flag);
	while (flag->point-- > 0)
		ft_putchar('0', flag);
	tmp = (unsigned int)va_arg(argp, int);
	ft_putint((unsigned int)tmp, flag);
	larg_flag_after(flag);
	return (0);
}
