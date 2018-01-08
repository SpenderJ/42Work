/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 18:31:59 by juspende          #+#    #+#             */
/*   Updated: 2018/01/08 18:34:54 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_revint(int *list)
{
	int		max;
	int		tmp;
	int		min;

	min = 0;
	max = list[0];
	if (list[0] <= 1)
		return ;
	while (++min < max)
	{
		tmp = list[min];
		list[min] = list[max];
		list[max] = tmp;
		--max;
	}
}
