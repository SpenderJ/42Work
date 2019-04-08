/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:17:36 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:17:37 by juspende         ###   ########.fr       */
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
