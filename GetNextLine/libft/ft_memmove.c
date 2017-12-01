/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 13:38:52 by juspende          #+#    #+#             */
/*   Updated: 2017/12/01 09:35:38 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*t1;
	char	*t2;
	size_t	i;
	char	*tmp;

	i = -1;
	t1 = (char*)src;
	t2 = (char*)dst;
	if ((tmp = malloc(sizeof(char) * len)) == NULL)
		return (dst);
	if (len <= 0)
		return (dst);
	while (++i < len)
		tmp[i] = t1[i];
	i = -1;
	while (++i < len)
		t2[i] = tmp[i];
	free(tmp);
	return (t2);
}
