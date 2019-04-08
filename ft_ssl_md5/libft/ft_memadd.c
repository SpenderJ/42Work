/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:17:20 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:17:25 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memadd(void *dest, const void *src, int beg, size_t n)
{
	unsigned int	i;
	const char		*tmp_src;
	char			*tmp_dest;

	i = 0;
	tmp_src = src;
	tmp_dest = dest;
	while (i < n)
	{
		tmp_dest[beg] = tmp_src[i];
		i++;
		beg++;
	}
	return (dest);
}
