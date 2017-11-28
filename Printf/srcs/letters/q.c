/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   q.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 13:16:33 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		q(va_list argp, const char *arg, int *index, t_flag *flag)
{
	(void)arg;
	(void)index;
	(void)argp;
	(void)flag;
	ft_putchar(arg[0], flag);
	return (-1);
}
