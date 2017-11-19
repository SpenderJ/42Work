/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:15:15 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 18:11:34 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strcmpi2(const char *c1, const char *c2)
{
	int			i;

	i = 0;
	while (c1[i] != '\0' && c2[i] != '\0')
	{
		if (c1[i] != c2[i])
			return (1);
		i = i + 1;
	}
	if (c1[i] == '\0' && c2[i] != '\0')
		return (1);
	return (0);
}

char			*ft_strstr(const char *str, const char *to_find)
{
	int			i;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0')
	{
		if (ft_strcmpi2(&str[i], to_find) == 0)
			return ((char *)&str[i]);
		i = i + 1;
	}
	return (NULL);
}
