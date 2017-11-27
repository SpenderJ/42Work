/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/27 11:39:37 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		c(va_list argp, const char *arg, int *index, t_flag *flag)
{
	(void)index;
	(void)flag;
	(void)arg;
	flag->larg = flag->larg - 1;
	larg_flag_before(flag);
	ft_putchar(va_arg(argp, int), flag);
	larg_flag_after(flag);
	return (0);
}
