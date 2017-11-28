/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:51:49 by exam              #+#    #+#             */
/*   Updated: 2017/11/07 11:02:48 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str)
{
	int		i;
	int		c;
	int		n;
	char	**tab;

	i = -1;
	c = 0;
	if ((tab = malloc(sizeof(char *) * 4096)) == NULL)
		return (NULL);
	while (str[c] != '\0')
	{
		while ((str[c] == ' ' || str[c] == '\n' || str[c] == '\t') && str[c] != '\0')
			++c;
		if (str[c] != ' ' && str[c] != '\n' && str[c] != '\t' && str[c] != '\0')
		{
			tab[++i] = malloc(sizeof(char) * 8192);
			tab[i + 1] = NULL;
			n = 0;
			while (str[c] != ' ' && str[c] != '\n' && str[c] != '\t' && str[c] != '\0')
				tab[i][n++] = str[c++];
		}
	}
	return (tab);
}
