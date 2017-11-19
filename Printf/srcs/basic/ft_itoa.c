/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:55:55 by juspende          #+#    #+#             */
/*   Updated: 2017/11/17 13:54:08 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/ft_printf.h"
#include <string.h>

static char	*goodmalloc(long n)
{
	long		c;
	long		d;
	char		*str;

	c = 1;
	d = 0;
	if (n < 0)
		n = -n;
	while (c < n)
	{
		c = c * 10;
		++d;
	}
	str = ft_strnew((int)d + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

char		*ft_itoa(int n)
{
	int					neg;
	char				*str;
	long				c;
	long				i;
	long				nbr;

	c = 0;
	i = 1;
	neg = (n >= 0) ? 1 : -1;
	nbr = (long)n;
	if ((str = goodmalloc(nbr)) == NULL)
		return (NULL);
	if (neg == -1 && (nbr = -nbr) >= 0)
		str[c++] = '-';
	while (i <= nbr)
		i = i * 10;
	if (nbr == 0)
		str[c++] = '0';
	while ((i = i / 10) >= 1)
	{
		str[c++] = (nbr / i + 48);
		nbr = nbr - (str[c - 1] - 48) * i;
	}
	str[c] = '\0';
	return (str);
}
