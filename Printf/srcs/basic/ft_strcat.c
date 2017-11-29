/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:28:53 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 11:25:33 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		a;

	i = -1;
	a = -1;
	if (dest)
		while (dest[++a] != '\0')
	if (a == -1)
		++a;
	if (src)
		while (src[++i] != '\0')
			dest[a++] = src[i];
	if (a == -1)
		++a;
	dest[a] = '\0';
	return (dest);
}
