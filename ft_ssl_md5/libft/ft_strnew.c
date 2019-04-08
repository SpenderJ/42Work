/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:21:48 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:21:50 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*str;
	unsigned int	i;

	if ((str = (char *)malloc(sizeof(*str) * size + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
	str[size] = '\0';
	return (str);
}
