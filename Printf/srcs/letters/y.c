/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   y.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 17:05:37 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		y(va_list argp, const char *arg, int *index, t_flag *flag)
{
	(void)argp;
	(void)arg;
	(void)index;
	(void)flag;
	if (flag->larg != 0)
		*index -= 1;
	*index = *index + int_len(flag->larg) + 1;
	flag->larg -= 1;
	larg_flag_before(flag);
	ft_putchar(arg[0], flag);
	larg_flag_after(flag);
	return (-1);
}
