/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/27 11:47:20 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		o(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char		*tmp;
	uintmax_t	sent;

	(void)arg;
	(void)index;
	length_modif_uox(argp, flag, &sent);
	tmp = ft_getnbr_base(sent, "01234567");
	flag->larg = flag->larg - ft_strlen(tmp);
	larg_flag_before(flag);
	if (ft_strlen(tmp) < flag->point && flag->point != 0)
		while (ft_strlen(tmp) < flag->point--)
			ft_putchar('0', flag);
	ft_putstr(tmp, flag);
	larg_flag_after(flag);
	return (0);
}
