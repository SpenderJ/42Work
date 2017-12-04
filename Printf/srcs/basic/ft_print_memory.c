/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 21:07:59 by juspende          #+#    #+#             */
/*   Updated: 2017/12/04 16:38:39 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		*ft_print_memory(char *addr, unsigned int size, t_flag *flag)
{
	int		i;
	int		len;
	int		b;

	i = 0;
	b = -1;
	(void)len;
	(void)size;
	if (!flag->zero)
		larg_flag_before(flag);
	ft_putnstr("0x", flag, &b);
//	printf("flag->comma = %d, flag->nbr = %d\n", flag->comma, flag->nbr);
	if (flag->comma && !flag->nbr)
		return (addr);
	if (flag->zero)
		larg_flag_before(flag);
	if (flag->point > 0)
		while (flag->point-- > 0)
			ft_putchar('0', flag);
	if (!flag->comma || (addr[0] != '0' && addr[1] != '\0'))
		ft_putnstr(addr, flag, &b);
	return (addr);
}
