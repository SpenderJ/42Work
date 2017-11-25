/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 15:47:55 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		p(va_list argp, const char *arg, int *index, t_flag *flag)
{
	(void)arg;
	(void)index;
	(void)flag;
	larg_flag_before(flag);
	ft_print_memory(va_arg(argp, void*), 1, flag);
	larg_flag_after(flag);
	return (0);
}
