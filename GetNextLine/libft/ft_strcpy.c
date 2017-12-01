/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:27:17 by juspende          #+#    #+#             */
/*   Updated: 2017/11/08 16:43:03 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a = a + 1;
	}
	dest[a] = '\0';
	return (dest);
}