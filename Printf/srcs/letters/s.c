/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 15:48:17 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		s(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	*tmp;

	(void)arg;
	(void)index;
	(void)flag;
	larg_flag_before(flag);
	tmp = va_arg(argp, char*);
	if (flag->comma == 0 && flag->point != 0)
		tmp[flag->point] = '\0';
	ft_putstr(tmp, flag);
	larg_flag_after(flag);
	return (0);
}
