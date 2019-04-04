/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:07:22 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 16:07:36 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_utf8_len(uintmax_t nbr)
{
	if (MB_CUR_MAX == 1)
	{
		if (nbr <= 255)
			return (1);
		else
			return (-1);
	}
	if ((nbr >= 0xd800 && nbr <= 0xdfff)
			|| (nbr >= 0x110000 && nbr <= 0x1fffff))
		return (-1);
	if (nbr <= 0x7f)
		return (1);
	else if (nbr > 0x7f && nbr <= 0xfff)
		return (2);
	else if (nbr > 0xfff && nbr <= 0xffff)
		return (3);
	else if (nbr > 0xffff && nbr <= 0x1fffff)
		return (4);
	else
		return (-1);
}
