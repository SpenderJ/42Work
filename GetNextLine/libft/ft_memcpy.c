/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:26:45 by juspende          #+#    #+#             */
/*   Updated: 2017/12/01 09:36:10 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*dstt;
	const char		*srcc;

	dstt = (char *)dst;
	srcc = (const char *)src;
	if (n == 0)
		return (dst);
	while (n--)
		*dstt++ = *srcc++;
	return (dst);
}
