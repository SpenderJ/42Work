/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:18:04 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:18:06 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*tmp_dest;
	const char	*tmp_src;

	i = 0;
	tmp_dest = dest;
	tmp_src = src;
	if (dest <= src)
	{
		while (i < n)
		{
			tmp_dest[i] = tmp_src[i];
			i++;
		}
	}
	else
	{
		while (n)
		{
			tmp_dest[n - 1] = tmp_src[n - 1];
			n--;
		}
	}
	return (dest);
}
