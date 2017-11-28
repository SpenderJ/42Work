/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 17:03:46 by juspende         ###   ########.fr       */
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
	if (flag->diez != 0)
		--flag->larg;
	larg_flag_before(flag);
	if (flag->diez != 0)
		ft_putchar('0', flag);
	if (ft_strlen(tmp) < flag->point && flag->comma != 0)
		while (ft_strlen(tmp) < flag->point--)
		{
			ft_putchar('0', flag);
			--flag->larg;
		}
	ft_putstr(tmp, flag);
	free (tmp);
	larg_flag_after(flag);
	return (0);
}
