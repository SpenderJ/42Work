/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:35:52 by juspende          #+#    #+#             */
/*   Updated: 2019/04/13 16:35:54 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t nbr, int base, char *abc)
{
	char	*result;
	int		i;

	i = ft_base_digitlen(nbr, base);
	if ((result = malloc(sizeof(char) * i + 1)) == NULL)
		return (NULL);
	result[i] = '\0';
	i--;
	while (i >= 0)
	{
		result[i] = abc[nbr % base];
		nbr = nbr / base;
		i--;
	}
	return (result);
}
