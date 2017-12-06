/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:05:03 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 18:04:45 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	s = (char *)malloc(sizeof(*s) * (len + 1));
	if (s == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	ft_strcpy(s, s1);
	ft_strcat(s, s2);
	return (s);
}
