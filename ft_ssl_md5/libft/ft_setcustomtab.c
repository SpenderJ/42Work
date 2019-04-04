/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setcustomtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:51:44 by jebossue          #+#    #+#             */
/*   Updated: 2016/12/01 15:51:45 by jebossue         ###   ########.fr       */
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
