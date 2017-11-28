/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:41:41 by exam              #+#    #+#             */
/*   Updated: 2017/11/07 12:04:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa_base(int value, int base)
{
	char	*result;
	char	*finalresult;
	char	*charbase;
	int		neg;
	int		i;
	int		c;
	int		res;

	neg = 1;
	if (value < 0)
	{
		value = -value;
		neg = -1;
	}
	finalresult = malloc(sizeof(char) * 4096);
	charbase = malloc(sizeof(char) * 4096);
	result = malloc(sizeof(char) * 4096);
	c = 0;
	res = 0;
	charbase = "0123456789ABCDEF";
	while (value >= base)
	{
		result[c] = charbase[value % base];
		value = value / base;
		++c;
	}
	result[c++] = charbase[value % base];
	if (neg == -1)
		result[c++] = '-';
	result[c] = '\0';
	i = 0;
	while (--c >= 0)
		finalresult[i++] = result[c];
	finalresult[i] = '\0';
	return(finalresult);
}
