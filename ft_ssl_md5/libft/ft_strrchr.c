/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:21:57 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:21:59 by juspende         ###   ########.fr       */
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
