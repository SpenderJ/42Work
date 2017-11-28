/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 17:04:34 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		u(va_list argp, const char *arg, int *index, t_flag *flag)
{
	uintmax_t	tmp;

	(void)index;
	if (arg[0] == 'U')
		flag->l = 1;
	length_modif_uox(argp, flag, &tmp);
	flag->point -= int_len(tmp);
	while (flag->point-- > 0)
		ft_putchar('0', flag);
	flag->larg -= int_len(tmp);
	larg_flag_before(flag);
	ft_putuint(tmp, flag);
	larg_flag_after(flag);
	return (0);
}
