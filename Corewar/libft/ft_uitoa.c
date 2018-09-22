/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:07:11 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 16:07:14 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_get_itoa(uintmax_t n, int size, char **nbr)
{
	while (n >= 10)
	{
		(*nbr)[size] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	(*nbr)[size] = n + '0';
}

char				*ft_uitoa(uintmax_t n)
{
	int				size;
	char			*nbr;

	size = ft_base_digitlen(n, 10);
	if ((nbr = (char*)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	nbr[size] = '\0';
	size--;
	ft_get_itoa(n, size, &nbr);
	return (nbr);
}
