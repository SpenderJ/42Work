/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:31:15 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/05 11:31:17 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int index;

	index = 0;
	while (s[index] != '\0' && (s[index] != c))
		index++;
	if (s[index] == c)
		return ((char *)s + index);
	else
		return (NULL);
}
