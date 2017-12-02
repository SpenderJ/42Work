/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:02:19 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 11:07:13 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t1;
	size_t			i;

	i = 0;
	t1 = (unsigned char*)s;
	while (i < n)
	{
		if (t1[i] == (unsigned char)c)
			return (t1 + i);
		++i;
	}
	return (NULL);
}
