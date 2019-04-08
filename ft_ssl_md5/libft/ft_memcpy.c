/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:17:55 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:17:57 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	const char		*tmp_src;
	char			*tmp_dest;

	i = 0;
	tmp_src = src;
	tmp_dest = dest;
	while (i < n)
	{
		tmp_dest[i] = tmp_src[i];
		i++;
	}
	return (dest + (int)n);
}
