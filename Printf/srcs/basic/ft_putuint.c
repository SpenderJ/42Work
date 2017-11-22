/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/04 15:06:32 by juspende          #+#    #+#             */
/*   Updated: 2017/11/22 17:02:46 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../../include/ft_printf.h"

void	ft_putuint(unsigned int nb, t_flag *flag)
{
	unsigned int	i;

	i = nb;
	if (i > 9)
	{
		ft_putuint(i / 10, flag);
		ft_putuint(i % 10, flag);
	}
	else
		ft_putchar(i + '0', flag);
}
