/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcustomtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:19:20 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:19:22 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_set_custom_tab(int x, int y, char c)
{
	char	**tab;
	int		i;

	if ((tab = (char **)malloc(sizeof(char*) * (x + 1))) == NULL)
		return (NULL);
	tab[x] = NULL;
	i = 0;
	while (i < x)
	{
		if ((tab[i] = (char *)malloc(sizeof(char) * (y + 1))) == NULL)
			return (NULL);
		tab[i][y] = '\0';
		i++;
	}
	x = -1;
	while (tab[++x])
	{
		i = 0;
		while (i < y)
		{
			tab[x][i] = c;
			i++;
		}
	}
	return (tab);
}
