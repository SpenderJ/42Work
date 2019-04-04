/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:43:45 by juspende          #+#    #+#             */
/*   Updated: 2018/01/28 14:11:50 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_freeall.h"

static void	arg_parser(va_list argp, char c)
{
	char	**tab;
	char	*str;
	int		i;

	i = -1;
	if (c == INT)
		free(va_arg(argp, int*));
	if (c == CHAR)
	{
		str = va_arg(argp, char*);
		free(str);
	}
	if (c == CHARR && (tab = va_arg(argp, char**)))
	{
		while (tab && tab[++i] != NULL)
			free(tab[i]);
		free(tab);
	}
}

int			ft_freeall(const char *list, ...)
{
	int			i;
	va_list		argp;

	i = -1;
	va_start(argp, list);
	while (list[++i] != '\0')
		if (list[i] == '%')
			arg_parser(argp, list[i + 1]);
	va_end(argp);
	return (END);
}
