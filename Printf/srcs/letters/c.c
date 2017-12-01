/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/01 12:14:03 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		c(va_list argp, const char *arg, int *index, t_flag *flag)
{
	unsigned char	i;

	(void)index;
	(void)flag;
	(void)arg;
	flag->larg = flag->larg - 1;
	larg_flag_before(flag);
	i = va_arg(argp, int);
	if (i == 0)
	{
		write(1, flag->printed, flag->charn);
		write(1, &i, 1);
		flag->charn += 1;
		free (flag->printed);
		flag->printed = ft_strnew(2);
	}
	else if(arg[0] == 'C' || flag->l)
		ft_putchar(i, flag);
	else
		ft_printchar(i, flag);
	larg_flag_after(flag);
	return (0);
}
