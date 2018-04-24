/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcattt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:28:53 by juspende          #+#    #+#             */
/*   Updated: 2018/01/27 10:41:09 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *restrict dest, const char *restrict src)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (dest[a] != '\0')
		a = a + 1;
	while (src[i] != '\0')
	{
		dest[a] = src[i];
		a = a + 1;
		i = i + 1;
	}
	dest[a] = '\0';
	return (dest);
}
