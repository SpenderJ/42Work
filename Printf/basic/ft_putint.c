/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:06:32 by juspende          #+#    #+#             */
/*   Updated: 2017/11/16 13:31:48 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/ft_printf.h"

void	ft_putint(int nb)
{
	unsigned int	i;

	if (nb < 0)
	{
		ft_putchar('-');
		i = -nb;
	}
	else
		i = nb;
	if (i > 9)
	{
		ft_putint(i / 10);
		ft_putint(i % 10);
	}
	else
		ft_putchar(i + '0');
}
