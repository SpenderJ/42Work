/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlistsorted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:12:54 by juspende          #+#    #+#             */
/*   Updated: 2018/01/27 10:54:05 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlisttruelysorted(int *list)
{
	int		i;

	i = 0;
	while (++i < list[0])
		if (list[i] > list[i + 1])
			return (1);
	return (0);
}

int		ft_intlistsorted(int *list)
{
	int		i;

	i = 0;
	while (++i < list[0])
		if (list[i] < list[i + 1])
			return (1);
	return (0);
}
