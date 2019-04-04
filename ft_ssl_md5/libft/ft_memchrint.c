/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:51:53 by jebossue          #+#    #+#             */
/*   Updated: 2017/01/11 17:59:58 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memchrint(const void *s, int c, size_t n)
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
			return (i);
		++i;
	}
	return (-1);
}
