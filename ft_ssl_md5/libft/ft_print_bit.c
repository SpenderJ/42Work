/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:18:24 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:18:25 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_octet(int nb)
{
	int	bit;
	int	mask;
	int	i;

	i = 7;
	mask = 128;
	while (i >= 0)
	{
		bit = (nb & mask) >> i;
		ft_putnbr(bit);
		mask >>= 1;
		i--;
	}
	ft_putchar('\n');
}

void	ft_print_bit(int nb)
{
	ft_print_octet(nb);
	if (nb > 0x007f && nb <= 0xfffff)
	{
		ft_print_octet(nb >> 8);
		if (nb > 0x07ff && nb <= 0xfffff)
		{
			ft_print_octet(nb >> 16);
			if (nb > 0xffff && nb < 0xfffff)
				ft_print_octet(nb >> 24);
		}
	}
	ft_putchar('\n');
}
