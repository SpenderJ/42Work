/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:37:21 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 20:59:57 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int		*tab;
	int		i;

	i = 0;
	if (min >= max)
		return (NULL);
	if ((tab = malloc(sizeof(int) * (max - min))) == NULL)
		return (NULL);
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
