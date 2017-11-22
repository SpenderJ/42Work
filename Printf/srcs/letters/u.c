/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 17:27:22 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		u(va_list argp, const char *arg, int *index, t_flag *flag)
{
	unsigned int	tmp;


	(void)arg;
	(void)index;
	(void)flag;
	tmp = (unsigned int)va_arg(argp, int);
	ft_putint((unsigned int)tmp, flag);
	return (0);
}
