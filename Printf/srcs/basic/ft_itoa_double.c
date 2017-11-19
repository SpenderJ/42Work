/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:55:55 by juspende          #+#    #+#             */
/*   Updated: 2017/11/18 17:06:48 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../include/ft_printf.h"
#include <string.h>

static char	*goodmalloc(long n, int index)
{
	double				c;
	double				d;
	char				*str;

	c = 1;
	d = 0;
	if (n < 0)
		n = -n;
	while (c < n)
	{
		c = c * 10;
		++d;
	}
	str = ft_strnew((int)d + 2 + index);
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	*add_next(char *str, int index, double nbr)
{
	int		i;

	i = -1;
	while (str[++i] != '\0')
		;
	str[i] = '.';
	while (index-- > 0 && (nbr = nbr * 10) != 0)
	{
		str[++i] = (int)nbr + 48;
		nbr = nbr - (str[i] - 48);
	}
	str[++i] = '\0';
	return (str);
}

char		*ft_itoa_double(double n, int index)
{
	int							neg;
	char						*str;
	double						c;
	double						i;
	double						nbr;

	c = 0;
	i = 1;
	nbr = n;
	neg = 0;
	if ((str = goodmalloc(nbr, index)) == NULL)
		return (NULL);
	if (neg == -1 && (nbr = -nbr) >= 0)
		str[(int)c++] = '-';
	while (i <= nbr)
		i = i * 10;
	if (nbr == 0)
		str[(int)c++] = '0';
	while ((i = i / 10) >= 1)
	{
		str[(int)c++] = (nbr / i + 48);
		nbr = nbr - (str[(int)c - 1] - 48) * i;
	}
	str[(int)c] = '\0';
	if (nbr == 0)
		return (str);
	return (add_next(str, index, nbr));
}
