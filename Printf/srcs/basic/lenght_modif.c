/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lenght_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 18:19:29 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 18:36:02 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		length_modif(va_list argp, t_flag *flag, intmax_t *tmp)
{
	if (flag->h != 0)
		*tmp = va_arg(argp, signed short int);
	else if (flag->l != 0)
		*tmp = va_arg(argp, long);
}
