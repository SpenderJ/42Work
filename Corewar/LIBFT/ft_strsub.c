/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 11:29:10 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/05 11:29:11 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	char			*s_2;
	unsigned int	u_i;

	if (s == NULL)
		return (NULL);
	u_i = 0;
	s_2 = (char *)s;
	str = (char *)malloc(sizeof(*str) * len + 1);
	if (str == NULL)
		return (NULL);
	while (s_2[start] && len > 0)
	{
		str[u_i] = s_2[start];
		u_i++;
		start++;
		len--;
	}
	str[u_i] = '\0';
	return (str);
}
