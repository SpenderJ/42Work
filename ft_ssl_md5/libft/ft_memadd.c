/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:04:56 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 16:04:58 by jebossue         ###   ########.fr       */
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
