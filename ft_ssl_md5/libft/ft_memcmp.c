/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:17:50 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:17:52 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	if ((s1 != NULL || s2 != NULL) && n != 0)
	{
		while (i < n - 1 && (tmp_s1[i] == tmp_s2[i]))
			i++;
	}
	return (tmp_s1[i] - tmp_s2[i]);
}
