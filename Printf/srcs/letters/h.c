/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/26 14:40:49 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		h(va_list argp, const char *arg, int *index, t_flag *flag)
{
	int			(*pointer)(va_list, const char*, int*, t_flag*);

	*index = *index + 1;
	if (arg[1] != 'h')
		flag->h = 1;
	else
	{
		*index = *index + 1;
		flag->hh = 1;
	}
	pointer = letter_parser[(int)arg[1] - 97];
	return ((*pointer)(argp, arg, index, flag));
}
