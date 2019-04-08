/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:21:17 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:21:20 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	unsigned int i;
	unsigned int length;

	i = 0;
	length = ft_strlen(dest);
	while (i < n && src[i])
	{
		dest[length + i] = src[i];
		i++;
	}
	dest[length + i] = '\0';
	return (dest);
}
