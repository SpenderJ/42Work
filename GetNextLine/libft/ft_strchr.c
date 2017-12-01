/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:30:35 by juspende          #+#    #+#             */
/*   Updated: 2017/12/01 09:22:41 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (c == 0)
			return ((char *)(s + ft_strlen(s)));
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
