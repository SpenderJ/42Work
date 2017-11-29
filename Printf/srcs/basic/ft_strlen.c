/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:25:53 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 10:35:41 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

size_t		ft_strlen(char *str)
{
	size_t		result;
	uint32_t	*i;
	
	result = 0;
	i = (uint32_t *)str;
	while (42)
	{
		if (!(*i & 0x000000ff))
			return result;
		if (!(*i & 0x0000ff00))
			return result + 1;
		if (!(*i & 0x00ff0000))
			return result + 2;
		if (!(*i & 0xff000000))
			return result + 3;
		result += 4;
	}
}
