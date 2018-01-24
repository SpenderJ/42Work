/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:32:23 by juspende          #+#    #+#             */
/*   Updated: 2018/01/24 15:43:02 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_placeint(int *list, int nb)
{
	int		i;
	int		min;

	i = 0;
	min = 30071998;
	while (++i <= list[0])
		if (list[i] < min)
			min = i;
	if (list[0] == 1)
	{
		printf("DAC\n");
		return (list[1]);
	}
	if (nb < list[min])
	{
		printf("MIN\n");
		return (list[min]);
	}
	i = min;
	while (nb > list[i])
	{
		if (i == list[0])
			i = 1;
		else
			++i;
		if (i == min)
		{
			printf("TG\n");
			printf("FDP\n");
			return (min == 1 ? list[list[0]] : list[min - 1]);
		}
	}
	printf("INSERTION APRES %d\n", list[i]);
	return (list[i]);
}

int			ft_posint(int *list, int nb)
{
	int			i;
	int			min;

	i = 0;
	min = 30071998;
	while (++i <= list[0])
		if (list[i] < min)
			min = i;
	if (list[0] == 1)
		return (1);
	if (nb < list[min])
		return (min);
	i = min;
	while (nb > list[i])
	{
		if (i == list[0])
			i = 1;
		else
			++i;
		if (i == min)
			return (min == 1 ? list[list[0]] : list[min - 1]);
	}
	return (i);
}
