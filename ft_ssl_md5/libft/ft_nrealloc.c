/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nrealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:18:19 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:18:21 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_nrealloc(char *buf, int newsize, int oldsize)
{
	char	*newbuf;

	newbuf = NULL;
	if ((newbuf = (char *)malloc(sizeof(char) * newsize)) == NULL)
		return (NULL);
	if (buf == NULL)
		return (newbuf);
	ft_memcpy(newbuf, buf, oldsize);
	free(buf);
	return (newbuf);
}
