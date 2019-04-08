/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:15:47 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:15:49 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_size_itoa(intmax_t n, unsigned int size)
{
	if (n == 0)
		return (size);
	size = ft_size_itoa(n / 10, size + 1);
	return (size);
}

static void			ft_get_itoa(long n, int size, char **nbr)
{
	int	is_neg;

	is_neg = n < 0 ? 1 : 0;
	if (is_neg)
	{
		(*nbr)[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{
		(*nbr)[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	(*nbr)[size] = n + '0';
}

char				*ft_itoa(intmax_t n)
{
	int		size;
	char	*nbr;
	int		is_neg;

	size = ft_size_itoa(n, 0);
	is_neg = n < 0 ? 1 : 0;
	if (is_neg || n == 0)
		size++;
	if ((nbr = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	nbr[size] = '\0';
	size--;
	ft_get_itoa((long)n, size, &nbr);
	return (nbr);
}
