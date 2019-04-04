/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:48:58 by jebossue          #+#    #+#             */
/*   Updated: 2016/11/24 15:50:00 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	const char		*tmp_src;
	char			*tmp_dest;

	tmp_src = src;
	tmp_dest = dest;
	i = 0;
	while (i < n)
	{
		if (tmp_src[i] == c)
		{
			tmp_dest[i] = c;
			return (dest + i + 1);
		}
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (NULL);
}
