/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:22:19 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:22:21 by juspende         ###   ########.fr       */
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
