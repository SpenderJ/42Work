/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:11:03 by juspende          #+#    #+#             */
/*   Updated: 2018/01/26 12:53:31 by juspende         ###   ########.fr       */
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

int		*ft_intnew(size_t size)
{
	int		*tofill;
	size_t	n;

	n = -1;
	if ((tofill = malloc(sizeof(int) * (size + 1))) == NULL)
		return (NULL);
	while (++n <= size)
		tofill[n] = 0;
	return (tofill);
}

int		*ft_intdup(int *list)
{
	int		*dup;
	int		c;

	dup = ft_intnew(list[0] + 1);
	c = -1;
	while (++c <= list[0])
		dup[c] = list[c];
	return (dup);
}
