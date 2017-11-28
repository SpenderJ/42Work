/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:06:32 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 11:44:14 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/ft_printf.h"

void	ft_putuint(uintmax_t nb, t_flag *flag)
{
	uintmax_t	i;

	i = nb;
	if (i > 9)
	{
		ft_putuint(i / 10, flag);
		ft_putuint(i % 10, flag);
	}
	else
		ft_putchar(i + '0', flag);
}
