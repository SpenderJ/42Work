/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/18 15:17:11 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		d(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		tmp;

	(void)arg;
	(void)flag;
	(void)index;
	tmp = va_arg(argp, int);
	if (tmp >= 0 && flag->pos == 1)
		ft_putchar('+');
	if (tmp >= 0 && flag->space == 1)
		ft_putchar(' ');
	ft_putint(tmp);
	return (0);
}
