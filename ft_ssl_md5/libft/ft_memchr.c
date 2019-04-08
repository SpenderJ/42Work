/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:17:40 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:17:42 by juspende         ###   ########.fr       */
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
