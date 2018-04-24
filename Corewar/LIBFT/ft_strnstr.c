/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:54:55 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 20:19:14 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && i + ft_strlen(to_find) <= len)
	{
		if (ft_strncmp((char *)&str[i], (char *)to_find, ft_strlen(to_find))
				== 0)
			return ((char *)&str[i]);
		i = i + 1;
	}
	return (NULL);
}
