/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 08:49:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		o(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char		*tmp;
	uintmax_t	sent;

	(arg[0] == 'O' ? flag->l = 1 : (int)flag);
	(void)index;
	length_modif_uox(argp, flag, &sent);
	tmp = ft_getnbr_base_ui(sent, "01234567");
	if (tmp[0] != '0' && tmp[1] != '\0')
		flag->larg = flag->larg - ft_strlen(tmp);
	if (flag->diez)
		--flag->larg;
	larg_flag_before(flag);
	if (flag->diez && tmp[0] != '0')
		ft_putchar('0', flag);
	if (ft_strlen(tmp) < flag->point && flag->comma)
		while (ft_strlen(tmp) < flag->point--)
		{
			ft_putchar('0', flag);
			--flag->larg;
		}
	ft_putoctal(tmp, flag);
	free (tmp);
	larg_flag_after(flag);
	return (0);
}
