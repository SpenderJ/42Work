/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 08:21:34 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		z(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int		(*pointer)(va_list, const char*, int*, t_flag*);

	if (arg[0] == 'Z')
	{
		*index = *index + int_len(flag->larg);
		flag->larg -= 1;
		larg_flag_before(flag);
		ft_putchar(arg[0], flag);
		larg_flag_after(flag);
		return (-1);
	}
	*index = *index + 1;
	flag->z = 1;
	if (arg[1] >= 'a')
		pointer = letter_parser[(int)arg[1] - 97];
	else
		pointer = letter_parser[(int)arg[1] - 97 + 32];
	return ((*pointer)(argp, &arg[1], index, flag));
}
