/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:32:09 by juspende          #+#    #+#             */
/*   Updated: 2017/11/08 17:03:30 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	while (n--)
	{
		*(unsigned char *)d++ = *(unsigned char *)s;
		if (*(unsigned char *)s++ == (unsigned char)c)
			return (d);
	}
	return (NULL);
}
