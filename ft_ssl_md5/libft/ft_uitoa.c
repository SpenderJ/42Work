/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:22:43 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:22:45 by juspende         ###   ########.fr       */
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
