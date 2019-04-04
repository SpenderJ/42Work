/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:06:55 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 16:06:58 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtab(int i, int j)
{
	char	**tab;

	tab = (char **)malloc(sizeof(*tab) * (i + 1));
	tab[i + 1] = NULL;
	i = 0;
	while (tab[i])
	{
		tab[i] = (char *)malloc(sizeof(tab) * (j + 1));
		tab[i][j + 1] = '\0';
		i++;
	}
	return (tab);
}
