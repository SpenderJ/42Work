/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:59:52 by jebossue          #+#    #+#             */
/*   Updated: 2016/11/25 14:24:09 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s)
{
	int	i;
	int	newlen;

	newlen = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[newlen - 1] == ' ' || s[newlen - 1] == '\n'
			|| s[newlen - 1] == '\t')
		newlen--;
	newlen = newlen - i + 1;
	return (newlen);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		newlen;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	if ((newlen = ft_count(s)) <= 0)
		newlen = 1;
	if ((str = (char*)malloc(sizeof(*str) * (newlen))) == NULL)
		return (NULL);
	j = 0;
	i = 0;
	k = 0;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k++;
	while (i++ < newlen - 1)
	{
		str[j] = s[k];
		j++;
		k++;
	}
	str[j] = '\0';
	return (str);
}
