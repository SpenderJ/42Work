/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:12:46 by juspende          #+#    #+#             */
/*   Updated: 2018/01/12 16:33:51 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printint(int *list)
{
	int		i;

	i = 0;
	while (++i <= list[0])
	{
		ft_putnbr(list[i]);
		ftt_putchar(' ');
	}
	ftt_putchar('\n');
	return ;
}
