/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnlmemcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:15:03 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:15:04 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

void	*ft_gnlmemcpy(void *dest, const void *src, size_t n)
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
	return (dest);
}
