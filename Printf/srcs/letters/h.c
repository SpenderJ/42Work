/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 17:43:32 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

int		h(va_list argp, const char *arg, int *index, t_flag *flag)
{
	short int	i;
	int			tmp;
	int			(*pointer)(va_list, const char*, int*, t_flag*);

	tmp = va_arg(argp, int);
	i = (short int)tmp;
	*index = *index + 1;
	flag->h = 1;
	pointer = letter_parser[(int)arg[1] - 97];
	return ((*pointer)(argp, arg, index, flag));
}
