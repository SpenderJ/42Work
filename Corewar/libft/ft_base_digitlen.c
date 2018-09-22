/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_digitlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 15:56:30 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 15:56:33 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_base_digitlen(uintmax_t nbr, int base)
{
	int	ln;

	ln = 0;
	if (nbr == 0)
		ln = 1;
	while (nbr != 0)
	{
		nbr = nbr / base;
		++ln;
	}
	return (ln);
}
