/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 16:36:28 by juspende          #+#    #+#             */
/*   Updated: 2017/11/18 17:48:24 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		ft_print_bits(void *buf)
{
	char	*ptr;
	int		i;
	int		j;

	i = -1;
	ptr = (char*)buf;
	while (ptr[++i] != '\0' && (j = 8) == 8) 
	{
		while (--j >= 0)
		{
			ft_putnbr_base((ptr[i] >> j) & 1, "0123456789ABCEDF");
		}
	}
}

void		ft_print_adress(void *buf)
{
	char	*ptr;

	ptr = (char *)buf;
	printf("coucou %s\n", ptr);
	ft_putnbr_base(ft_atoi(ptr), "0123456789ABCDEF");
}
