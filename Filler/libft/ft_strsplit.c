/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 09:59:44 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 18:04:26 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_space(char *str, char c)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			res = res + 1;
		i = i + 1;
	}
	return (res + 1);
}

static char	*str_to_next_tab(char *str, char c)
{
	int		i;
	char	*final;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i = i + 1;
	if ((final = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = -1;
	while (str[++i] != '\0' && str[i] != c)
		final[i] = str[i];
	final[i] = '\0';
	return (final);
}

char		**ft_strsplit(char const *str, char c)
{
	int		i;
	char	**tab;
	int		a;

	i = 0;
	a = -1;
	if (!str)
		return (NULL);
	if ((tab = malloc(sizeof(char *) * (count_space((char *)str, c) + 1)))
			== NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && (str[i] == c))
			i++;
		if (str[i] != '\0')
			tab[++a] = str_to_next_tab((char *)&str[i], c);
		while (str[i] != '\0' && str[i] != c)
			i = i + 1;
	}
	tab[++a] = NULL;
	return (tab);
}
