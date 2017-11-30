/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/30 17:23:36 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		n(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		*res;

	(void)arg;
	(void)flag;
	res = va_arg(argp, int *);
	*res = *index - 1;
	return (0);
}
