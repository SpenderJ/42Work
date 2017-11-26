/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 22:37:51 by juspende          #+#    #+#             */
/*   Updated: 2017/11/26 16:45:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int		my_error(char *base)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	if (!(base) || base[0] == '\0' || base[1] == '\0')
		return (84);
	while (base[i] != '\0')
	{
		n = 0;
		if (base[i] == '-' || base[i] == '+')
			return (84);
		while (base[n] != '\0')
		{
			if (n == i)
				++n;
			else
			{
				if (base[n++] == base[i])
					return (84);
			}
		}
		i = i + 1;
	}
	return (0);
}

char			*ft_getnbr_base_ui(intmax_t nbr, char *base)
{
	char			*str;
	intmax_t		i;
	int				x;
	intmax_t		nb;

	i = 0;
	x = 0;
	if ((str = ft_strnew(4096)) == NULL)
		return (NULL);
	while (base[i] != '\0')
		i = i + 1;
	nb = nbr;
	while (nb >= i)
	{
		str[x++] = base[(nb % i)];
		nb = nb / i;
	}
	str[x++] = base[(nb % i)];
	return (ft_strrev(str));
}
