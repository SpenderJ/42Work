/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 14:26:35 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 20:32:28 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i] != '\0')
		++i;
	if ((str = malloc(sizeof(char) * (i + 2))) == NULL)
		return (NULL);
	i = 0;
	printf("a %s\n\n", src);
	while (src[i] != '\0')
	{
//		printf("wut\n");
		str[i] = src[i];
		++i;
	}
	str[i] = '\0';
	return (str);
}
