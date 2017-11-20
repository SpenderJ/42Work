/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/18 15:52:44 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		o(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	*tmp;
	int		c;

	c = 0;
	(void)arg;
	(void)index;
	(void)flag;
	tmp = ft_getnbr_base(va_arg(argp, int), "01234567");
	if (ft_strlen(tmp) < flag->point && flag->point != 0)
		while (ft_strlen(tmp) < flag->point--)
			ft_putchar('0');
	ft_putstr(tmp);
	return (0);
}
