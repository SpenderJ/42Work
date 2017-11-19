/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:11:03 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 18:06:58 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tofill;
	size_t	n;

	n = -1;
	if ((tofill = malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (++n <= size)
		tofill[n] = '\0';
	return (tofill);
}
