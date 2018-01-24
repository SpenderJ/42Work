/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:32:23 by juspende          #+#    #+#             */
/*   Updated: 2018/01/24 18:43:14 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_placeint(int *list, int nb)
{
	int		i;
	int		min;

	i = 0;
	min = 1;
	printf("PLACEINT\n");
	while (++i <= list[0])
		if (list[i] < list[min])
			min = i;
	printf("PLACEINT DEBUG\n");
	if (list[0] == 1)
		return (list[1]);
	else if (nb < list[min])
		return (list[min]);
	i = min;
	printf("[[PLACEINT DEBUG]]\n");
	while (nb > list[i])
	{
		if (i != 1)
			--i;
		else
			i = list[0];
		if (i == min)
		{
			printf("JSUIS RELOU\n");
			return (min == 0 ? list[0] : list[min]);
		}
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
	printf("[[PRINTINT DEBUG START]\n\n");
	while (nb > list[i])
	{
	printf("In While Number = %d list[i] = %d, i = %d\n", nb, list[i], i); 
		if (i != 1)
			--i;
		else
			i = list[0];
		if (i == min)
		{
			printf("[PRINTINT BOUCLE ENTIERE] RETURNED = %d\n", min);
			return (min == 0 ? 0 : min);
		}
	}
	printf("[PRINTINT RANKING] END POF NORMAL\n");
	return (i);
}
