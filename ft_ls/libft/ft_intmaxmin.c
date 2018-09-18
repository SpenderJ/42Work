/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmaxmin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 13:57:24 by juspende          #+#    #+#             */
/*   Updated: 2018/01/26 13:59:55 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intmax(int *list)
{
	int		i;
	int		max;

	i = 0;
	max = list[1];
	while (++i < list[0])
		if (max < list[i])
			max = list[i];
	return (max);
}

int		ft_intmin(int *list)
{
	int		i;
	int		min;

	i = 0;
	min = list[1];
	while (++i < list[0])
		if (min > list[i])
			min = list[i];
	return (min);
}
