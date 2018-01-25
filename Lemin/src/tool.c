/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:31:18 by juspende          #+#    #+#             */
/*   Updated: 2018/01/25 09:08:29 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "my_h.h"

int     my_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i] != 0 && str2[i] != 0)
	{
		if (str[i] != str2[i])
			return (1);
		i++;
	}
	if (str[i] != 0 || str2[i] != 0)
		return (1);
	else
		return (0);
}

int	at_oi(char *str)
{
	int	nbr;
	int	i;
	int	s;

	i = 0;
	nbr = 0;
	if (str[i] == '-')
	{
		s = -1;
		++i;
	}
	else
		s = 1;
	while (str[i] != 0 && str[i] != '\n')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nbr = nbr * 10 + (str[i] - 48);
		++i;
	}
	return (nbr * s);
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i += 1;
	return (i);
}

int	p_s(char *str, int i)
{
	int	y;

	if (i == 1)
		ft_printf("##start\n");
	else
		ft_printf("##end\n");
	y = 0;
	while (str[y] != 0 && str[y] != '#')
	{
		ft_printf("%c", str[y]);
		++y;
	}
	write(1, "\n", 1);
	return (0);
}

int     fb(char **tab)
{
	int   i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i += 1;
	}
	return (0);
}
