/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 14:15:34 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		x(va_list argp, const char *arg, int *index, t_flag *flag)
{
	unsigned int	tmp;

	(void)index;
	(void)flag;
	tmp = (unsigned int)va_arg(argp, int);
	if (arg[0] == 'X')
		ft_putnbr_base((int)tmp, "0123456789ABCDEF");
	else
		ft_putnbr_base((int)tmp, "0123456789abcdef");
	return (0);
}
