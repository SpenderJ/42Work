/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/26 16:22:11 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		u(va_list argp, const char *arg, int *index, t_flag *flag)
{
	intmax_t	tmp;

	(void)arg;
	(void)index;
	(void)flag;
	larg_flag_before(flag);
	while (flag->point-- > 0)
		ft_putchar('0', flag);
	length_modif_uox(argp, flag, &tmp);
	ft_putint(tmp, flag);
	larg_flag_after(flag);
	return (0);
}
