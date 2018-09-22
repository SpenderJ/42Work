/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdoublon.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:22:23 by jebossue          #+#    #+#             */
/*   Updated: 2017/06/07 14:59:24 by jebossue         ###   ########.fr       */
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
