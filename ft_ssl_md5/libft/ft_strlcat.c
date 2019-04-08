/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:20:58 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:20:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_length;

	dest_length = ft_strlen(dest);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size == dest_length + ft_strlen(src))
		return (size);
	if (size < dest_length)
		return (ft_strlen(src) + size);
	if (dest_length + ft_strlen(src) > size)
		return (dest_length + ft_strlen(src));
	return (i);
}
