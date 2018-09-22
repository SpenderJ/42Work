/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:04:25 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 16:04:28 by jebossue         ###   ########.fr       */
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
