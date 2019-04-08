/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_digitlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:14:47 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:14:48 by juspende         ###   ########.fr       */
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
