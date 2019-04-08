/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:15:31 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:15:32 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_maxou(long int nb, char *str)
{
	if ((nb == 0 && ft_strcmp(str, "0") != 0) || (nb > 2147483647 ||
				nb < -2147483648))
		return (0);
	if (ft_isnbr(ft_atoi_long(str)) == 0)
		return (0);
	return (1);
}

int			ft_isint(char **av)
{
	long int	nb;
	int			i;
	int			j;
	char		*tmp;

	i = 0;
	while (av[i])
	{
		j = 0;
		tmp = av[i];
		while (tmp[j] != '\0')
		{
			if (tmp[0] == '-' || tmp[0] == '+')
				tmp++;
			if (tmp[j] < '0' || tmp[j] > '9')
				return (0);
			j++;
		}
		nb = ft_atoi_long(av[i]);
		if (ft_maxou(nb, av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
