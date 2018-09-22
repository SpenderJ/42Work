/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nrealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mverdier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:20:21 by mverdier          #+#    #+#             */
/*   Updated: 2016/11/18 11:47:54 by mverdier         ###   ########.fr       */
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
