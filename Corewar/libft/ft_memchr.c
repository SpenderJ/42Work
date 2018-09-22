/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:49:15 by jebossue          #+#    #+#             */
/*   Updated: 2016/11/22 13:53:38 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		tmp_c;
	size_t				i;
	const unsigned char	*tmp_s;

	tmp_c = (unsigned char)c;
	tmp_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == tmp_c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
