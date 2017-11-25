/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:44:26 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 16:49:19 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	larg_flag_before(t_flag *flag)
{
	int		i;

	i = 0;
	if (flag->neg != 0)
		return ;
	while (i < flag->larg)
	{
		++i;
		ft_putchar(' ', flag);
	}
}

void	larg_flag_after(t_flag *flag)
{
	int		i;

	i = 0;
	if (flag->neg == 0)
		return ;
	while (i < flag->larg)
	{
		++i;
		ft_putchar(' ', flag);
	}
}
