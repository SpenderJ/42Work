/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:32:23 by juspende          #+#    #+#             */
/*   Updated: 2018/01/26 18:49:49 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_placeint(int *list, int nb)
{
	int		i;
	int		min;

	i = 0;
	min = 1;
	while (++i <= list[0])
		if (list[i] < list[min])
			min = i;
	if (list[0] == 1)
		return (list[1]);
	else if (nb < list[min])
		return (list[min]);
	i = min;
	while (nb > list[i])
	{
		if (i != 1)
			--i;
		else
			i = list[0];
		if (i == min)
			return (min == 0 ? list[0] : list[min]);
	}
	return (list[i]);
}

int			ft_posint(int *list, int nb)
{
	int			i;
	int			min;

	i = 0;
	min = 1;
	while (++i <= list[0])
		if (list[i] < list[min])
			min = i;
	if (list[0] == 1)
		return (1);
	else if (nb < list[min])
		return (min);
	i = min;
	while (nb > list[i])
	{
		if (i != 1)
			--i;
		else
			i = list[0];
		if (i == min)
			return (min == 0 ? 0 : min);
	}
	return (i);
}
