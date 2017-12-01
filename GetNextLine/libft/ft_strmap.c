/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:36:23 by juspende          #+#    #+#             */
/*   Updated: 2017/11/09 18:05:23 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
		++i;
	if ((str = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (s[++i] != '\0')
		str[i] = f(s[i]);
	str[i] = '\0';
	return (str);
}
