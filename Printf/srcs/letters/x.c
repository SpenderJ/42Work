/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 16:33:54 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		x(va_list argp, const char *arg, int *index, t_flag *flag)
{
	unsigned int	tmp;

	(void)index;
	(void)flag;
	larg_flag(flag);
	tmp = (unsigned int)va_arg(argp, int);
	if (arg[0] == 'X')
		ft_putnbr_base((int)tmp, "0123456789ABCDEF", flag);
	else
		ft_putnbr_base((int)tmp, "0123456789abcdef", flag);
	return (0);
}
