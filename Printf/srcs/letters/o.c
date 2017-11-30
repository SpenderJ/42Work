/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/30 20:59:28 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	parser_o_flags(t_flag *flag, char *tmp)
{
	flag->diez ? flag->larg -= 1 : flag->larg;
	flag->point -= ft_strlen(tmp);
	flag->larg -= ft_strlen(tmp);
	if (flag->point < 0)
		flag->point = 0;
	flag->larg -= flag->point;
}

int		o(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char		*tmp;
	uintmax_t	sent;
	int			b;

	b = 0;
	arg[0] == 'O' ? flag->l = 1 : flag->l;
	(void)index;
	length_modif_uox(argp, flag, &sent);
	tmp = ft_getnbr_base_ui(sent, "01234567");
	if (flag->comma && !flag->point && !sent)
		b = -1;
	parser_o_flags(flag, tmp);
	larg_flag_before(flag);
	if (flag->diez && tmp[0] != '0')
		ft_putchar('0', flag);
	while (flag->point--)
		ft_putchar('0', flag);
	if (b != -1 || flag->diez)
		ft_putoctal(tmp, flag);
	free (tmp);
	larg_flag_after(flag);
	return (0);
}
