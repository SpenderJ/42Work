/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/01 12:14:05 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		s(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	*tmp;
	int		i;
	int		b;

	i = -1;
	b = 0;
	(void)arg;
	(void)index;
	tmp = va_arg(argp, char*);
	if (!tmp && !flag->comma)
		tmp = ft_strdup("(null)");
	if (flag->larg != 0 && (int)ft_strlen(tmp) > flag->larg)
		tmp[flag->larg] = '\0';
	if (flag->comma && (int)ft_strlen(tmp) > flag->point && flag->point > 0)
		tmp[flag->point] = '\0';
	if (flag->comma && !flag->point && (b = -1))
		;
	flag->larg = flag->larg - ft_strlen(tmp);
	larg_flag_before(flag);
	if (b != -1)
		ft_putnstr(tmp, flag, &i);
	if (b == -1 && tmp && tmp[0] != '0')
		ft_printchar('0', flag);
	larg_flag_after(flag);
	return (0);
}
