/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/26 16:21:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		o(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char		*tmp;
	int			c;
	intmax_t	sent;

	c = 0;
	(void)arg;
	(void)index;
	length_modif_uox(argp, flag, &sent);
	larg_flag_before(flag);
	tmp = ft_getnbr_base(sent, "01234567");
	if (ft_strlen(tmp) < flag->point && flag->point != 0)
		while (ft_strlen(tmp) < flag->point--)
			ft_putchar('0', flag);
	ft_putstr(tmp, flag);
	larg_flag_after(flag);
	return (0);
}
