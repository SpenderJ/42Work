/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:14:37 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:14:39 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				negativ;
	unsigned int	i;
	long int		nb;

	negativ = 1;
	i = 0;
	nb = 0;
	while (nptr[i] && (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
				|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			negativ = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb = nb * 10 + nptr[i] - 48;
		i++;
	}
	return ((int)(nb * negativ));
}
