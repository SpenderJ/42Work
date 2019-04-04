/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 21:10:07 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 18:04:56 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dest, const char *src, size_t size)
{
	size_t	i;
	size_t	a;
	size_t	res;

	a = 0;
	i = 0;
	while (dest[i] != '\0')
		i = i + 1;
	res = 0;
	while (src[res] != '\0')
		res = res + 1;
	if (size <= i)
		res += size;
	else
		res += i;
	while (src[a] != '\0' && i + 1 < size)
	{
		dest[i] = src[a];
		i = i + 1;
		a = a + 1;
	}
	dest[i] = '\0';
	return (res);
}
