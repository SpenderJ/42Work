/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:21:38 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:21:40 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*s_cpy;
	size_t	i;

	i = 0;
	if ((s_cpy = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	while (i < n && s[i])
	{
		s_cpy[i] = s[i];
		i++;
	}
	s_cpy[i] = '\0';
	return (s_cpy);
}
