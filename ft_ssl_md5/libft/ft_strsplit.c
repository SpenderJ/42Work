/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:22:03 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:22:05 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_doit(char **array, char const *s, char c, int j)
{
	int	i;
	int start;
	int len;

	i = -1;
	while (s[++i])
	{
		len = 0;
		while (s[i] != c && s[i])
		{
			if (i == 0 || s[i - 1] == c)
			{
				j++;
				start = i;
			}
			i++;
			len++;
		}
		if (i != 0 && s[i - 1] != c)
			array[j] = ft_strsub(s, start, len);
		if (s[i] == '\0')
			i--;
	}
	array[j + 1] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**array;
	int		nbrwords;

	if (!s)
		return (NULL);
	nbrwords = ft_nbrwords(s, c) + 1;
	if ((array = (char**)malloc(sizeof(*array) * nbrwords)) == NULL)
		return (NULL);
	ft_doit(array, s, c, -1);
	return (array);
}
