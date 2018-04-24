/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend_or_append.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:57:47 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:22:20 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_prepend(char *buf, int n, char c)
{
	char		*prepend;
	int			i;

	i = 0;
	prepend = (char *)malloc(sizeof(char) * n + 1);
	if (prepend)
	{
		while (i < n)
			prepend[i++] = c;
	}
	prepend[i] = '\0';
	return (ft_strjoin_clr(prepend, buf, 2));
}

char			*ft_append(char *buf, int n, char c)
{
	char		*append;
	int			i;

	i = 0;
	append = (char *)malloc(sizeof(char) * n + 1);
	if (append)
	{
		while (i < n)
			append[i++] = c;
	}
	append[i] = '\0';
	return (ft_strjoin_clr(buf, append, 2));
}
