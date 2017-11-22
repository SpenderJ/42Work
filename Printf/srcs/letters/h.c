/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 16:32:23 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		h(va_list argp, const char *arg, int *index, t_flag *flag)
{
	short int	i;
	int			tmp;

	(void)arg;
	(void)index;
	(void)flag;
	tmp = va_arg(argp, int);
	i = (short int)tmp;
	ft_putshort(i, flag);
	return (0);
}
