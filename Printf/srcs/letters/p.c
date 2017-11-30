/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/30 17:23:41 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		p(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char		*str;
	uintmax_t	tmp;
	void		*stack;

	(void)arg;
	(void)index;
	stack = va_arg(argp, void*);
	tmp = (unsigned long int)stack;
	flag->larg = flag->larg - 2;
	str = ft_getnbr_base_ui(tmp, "01234567889abcdef");
	flag->larg -= ft_strlen(str);
	larg_flag_before(flag);
	ft_print_memory(stack, 1, flag);
	larg_flag_after(flag);
	return (0);
}
