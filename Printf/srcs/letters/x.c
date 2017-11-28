/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 13:17:44 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		x(va_list argp, const char *arg, int *index, t_flag *flag)
{
	uintmax_t		tmp;
	char			*fnl;

	(void)index;
	length_modif_uox(argp, flag, &tmp);
	if ((char)arg[0] == 'X')
		fnl = ft_getnbr_base_ui(tmp, "0123456789ABCDEF");
	else
		fnl = ft_getnbr_base_ui(tmp, "0123456789abcdef");
	if (fnl[0] != '0')
		flag->larg = flag->larg - ft_strlen(fnl);
	(flag->diez != 0 ? flag->larg = flag->larg - 2 : flag->larg);
	if (flag->zero == 0)
		larg_flag_before(flag);
	if (flag->diez != 0 && fnl[0] != '0')
	{
		ft_putstr("0", flag);
		ft_putchar(arg[0], flag);
	}
	if (flag->zero != 0)
		larg_flag_before(flag);
	ft_putstr(fnl, flag);
	larg_flag_after(flag);
	free (fnl);
	return (0);
}
