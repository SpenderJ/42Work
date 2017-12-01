/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:27:50 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 18:06:28 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	a;

	a = 0;
	while (src[a] != '\0' && a < n)
	{
		dest[a] = src[a];
		a = a + 1;
	}
	while (a < n)
	{
		dest[a] = '\0';
		++a;
	}
	return (dest);
}
