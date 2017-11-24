/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 17:06:24 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		s(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	*tmp;

	(void)arg;
	(void)index;
	(void)flag;
	larg_flag(flag);
	tmp = va_arg(argp, char*);
	if (flag->comma == 0 && flag->point != 0)
		tmp[flag->point] = '\0';
	ft_putstr(tmp, flag);
	return (0);
}
