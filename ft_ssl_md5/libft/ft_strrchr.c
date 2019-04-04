/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:00:09 by jebossue          #+#    #+#             */
/*   Updated: 2016/11/22 14:17:48 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*tmp_s;

	tmp_s = (char *)s;
	i = ft_strlen(s);
	while (i != 0 && tmp_s[i] != (char)c)
		i--;
	if (tmp_s[i] != (char)c)
		return (NULL);
	return (tmp_s + i);
}
