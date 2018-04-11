/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 10:47:57 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/07 10:49:07 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			aide_itoa(int len, int nbr, int value, int base)
{
	nbr = value;
	while (nbr)
	{
		nbr /= base;
		len += 1;
	}
	nbr = value;
	if (nbr < 0)
		if (base == 10)
			len += 1;
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	int		len;
	long	nbr;
	char	*pointer;
	char	*base_string;

	base_string = "0123456789ABCDEF";
	if (value == 0)
		return (ft_strndup("0", 1));
	if (value == -2147483648 && base == 10)
		return (ft_strdup("-2147483648"));
	nbr = 0;
	len = aide_itoa(0, nbr, value, base);
	nbr = (value < 0) ? -value : value;
	if (!(pointer = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	pointer[len] = '\0';
	while (nbr)
	{
		pointer[--len] = base_string[nbr % base];
		nbr /= base;
	}
	if (value < 0 && base == 10)
		pointer[0] = '-';
	return (pointer);
}
