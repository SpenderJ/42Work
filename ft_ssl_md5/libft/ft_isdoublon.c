/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdoublon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:15:27 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:15:28 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdoublon(char **av)
{
	int	i;
	int	nb;
	int	nbcomp;

	while (*av)
	{
		nb = ft_atoi_long(*av);
		i = 0;
		av++;
		while (*av)
		{
			i++;
			nbcomp = ft_atoi_long(*av);
			if (nb == nbcomp)
				return (0);
			av++;
		}
		av = av - i;
	}
	return (1);
}
