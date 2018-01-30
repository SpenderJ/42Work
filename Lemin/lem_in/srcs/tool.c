/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 13:12:34 by juspende          #+#    #+#             */
/*   Updated: 2018/01/30 13:14:08 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			p_s(char *str, int i)
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

int			fb(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i += 1;
	}
	return (0);
}
