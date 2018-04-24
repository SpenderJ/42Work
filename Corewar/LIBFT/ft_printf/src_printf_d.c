/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src_printf_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:50:15 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/19 15:57:42 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_eq_char(char c1, char c2)
{
	if (c1 == c2)
		return (1);
	else
		return (0);
}

int			ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int			ft_max(size_t n, size_t p)
{
	if (n > p)
		return (n);
	return (p);
}

int			ft_abs(int n)
{
	return (n < 0 ? -n : n);
}

long long	ft_abs_ll(long long n)
{
	return (n < 0 ? -n : n);
}
