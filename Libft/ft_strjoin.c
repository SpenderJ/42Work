/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:05:03 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 18:04:27 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		res;
	int		c;

	if ((c = 0) == 0 && !s1 && !s2)
		return (NULL);
	if (s1)
		while (s1[c] != '\0')
			++c;
	res = c + 1;
	if (s2 && (c = 0) == 0)
		while (s2[c] != '\0')
			++c;
	res = res + c + 1;
	c = -1;
	if ((final = malloc(sizeof(char) * res)) == NULL)
		return (NULL);
	res = 0;
	while (s1 && s1[++c] != '\0')
		final[res++] = s1[c];
	c = -1;
	while (s2 && s2[++c] != '\0')
		final[res++] = s2[c];
	final[res] = '\0';
	return (final);
}
