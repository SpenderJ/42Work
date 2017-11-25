/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 16:48:47 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		x(va_list argp, const char *arg, int *index, t_flag *flag)
{
	unsigned int	tmp;
	char			*fnl;

	(void)index;
	(void)flag;
	tmp = (unsigned int)va_arg(argp, int);
	if ((char)arg[0] == 'X')
		fnl = ft_getnbr_base_ui(tmp, "0123456789ABCDEF");
	else
		fnl = ft_getnbr_base_ui(tmp, "0123456789abcdef");
	if (ft_strlen(fnl) < flag->larg)
		flag->larg = flag->larg - ft_strlen(fnl);
	else
		flag->larg = 0;
	larg_flag_before(flag);
	ft_putstr(fnl, flag);
	larg_flag_after(flag);
	free (fnl);
	return (0);
}
