/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:45:02 by juspende          #+#    #+#             */
/*   Updated: 2017/11/12 00:46:51 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

int		empty_line(char *str)
{
	int		i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] != '\0')
		if (str[i] != '.')
			return (0);
	return (1);
}

int		empty_col(char **tab, int index)
{
	int		i;

	i = -1;
	if (!tab)
		return (0);
	while (tab[++i])
	{
		if (tab[i][index] != '.' && tab[i][index] != '\0')
			return (0);
	}
	return (1);
}
