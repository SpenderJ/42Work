/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/30 18:04:10 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		u(va_list argp, const char *arg, int *index, t_flag *flag)
{
	uintmax_t	tmp;
	int			b;

	(void)index;
	b = 0;
	if (arg[0] == 'U')
		flag->l = 1;
	length_modif_uox(argp, flag, &tmp);
	if (flag->comma && !flag->point && !flag->nbr)
		b = -1;
	flag->point -= int_len(tmp);
	flag->larg -= int_len(tmp);
	if (flag->point < 0)
		flag->point = 0;
	flag->larg -= flag->point;
	larg_flag_before(flag);
	while (flag->point-- > 0)
		ft_putchar('0', flag);
	if (b != -1)
		ft_putuint(tmp, flag);
	larg_flag_after(flag);
	return (0);
}
