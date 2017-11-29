/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 10:56:47 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		s(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	*tmp;

	(void)arg;
	(void)index;
	(void)flag;
	tmp = ft_strdup(va_arg(argp, char*));
	if (flag->larg != 0 && (int)ft_strlen(tmp) > flag->larg)
		tmp[flag->larg] = '\0';
	if (flag->comma != 0 && (int)ft_strlen(tmp) > flag->point)
		tmp[flag->point] = '\0';
	flag->larg = flag->larg - ft_strlen(tmp);
	larg_flag_before(flag);
	ft_putstr(tmp, flag);
	larg_flag_after(flag);
	return (0);
}
