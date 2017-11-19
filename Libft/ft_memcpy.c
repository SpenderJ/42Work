/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:26:45 by juspende          #+#    #+#             */
/*   Updated: 2017/11/08 17:30:06 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*dstt;
	const char	*srcc;

	dstt = (char *)dst;
	srcc = (const char *)src;
	if (n == 0)
		return (dst);
	while (n--)
		*dstt++ = *srcc++;
	return (dst);
}
