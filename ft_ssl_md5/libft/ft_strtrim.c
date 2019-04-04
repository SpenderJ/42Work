/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:13:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/07 20:20:40 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		sd;
	int		se;
	char	*str;
	int		len;
	int		c;

	c = 0;
	if (!s)
		return (NULL);
	len = ft_strrlen(s);
	sd = 0;
	se = len - 1;
	while (s[sd] && (s[sd] == ' ' || s[sd] == '\t' || s[sd] == '\n'))
		++sd;
	while (se > 0 && (s[se] == ' ' || s[se] == '\t' || s[se] == '\n') && ++c)
		--se;
	if (len - sd <= 0)
		return (ft_strdup(""));
	if ((str = ft_strnew(len - sd - c)) == NULL)
		return (NULL);
	c = 0;
	while (s[sd] != '\0' && sd <= se)
		str[c++] = s[sd++];
	str[c] = '\0';
	return (str);
}
