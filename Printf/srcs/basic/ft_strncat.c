/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:29:00 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 21:36:41 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t	i;
	size_t	a;

	i = -1;
	a = -1;
	if (dest)
		while (dest[++a] != '\0')
			;
	if ((int)a == -1)
		++a;
	if (src)
		while (src[++i] != '\0' && i < nb)
			dest[a++] = src[i];
	dest[a] = '\0';
	return (dest);
}
