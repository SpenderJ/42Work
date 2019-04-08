/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:20:53 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:20:55 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;
	int		y;

	if (!(s1) || !(s2))
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if ((str = (char *)malloc(sizeof(*str) * len)) == NULL)
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
	{
		str[i] = s2[y];
		i++;
		y++;
	}
	str[i] = '\0';
	return (str);
}
