/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tabtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:26:24 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/06 13:10:28 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

static char	*ft_strdup(const char *src)
{
	char	*str;
	int		index;

	index = 0;
	while (src[index])
		index++;
	if (!(str = (char *)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	str[index] = 0;
	index = -1;
	while (src[++index])
		str[index] = src[index];
	return (str);
}

static char	**ft_create(int size_y, char **tab, char *str)
{
	if (!(tab = (char **)malloc(sizeof(char *) * (size_y + 1))))
		return (NULL);
	tab[0] = ft_strdup(str);
	tab[1] = NULL;
	return (tab);
}

static char	**ft_new(int size_y, char **tab, char *str)
{
	char	**t;
	int		i;

	i = -1;
	if (!(t = (char **)malloc(sizeof(char *) * (size_y + 1))))
		return (NULL);
	t[size_y] = NULL;
	while (tab[++i])
		t[i] = ft_strdup(tab[i]);
	t[i] = ft_strdup(str);
	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	ft_strdel(&tab[i]);
	free(tab);
	tab = NULL;
	return (t);
}

char		**ft_malloc_tabtab(char **tab, char *str)
{
	int size_y;

	if (!str)
		return (NULL);
	if (!tab)
	{
		if ((tab = ft_create(1, tab, str)) == NULL)
			return (NULL);
	}
	else
	{
		size_y = 0;
		while (tab[size_y])
			size_y++;
		if ((tab = ft_new(size_y + 1, tab, str)) == NULL)
			return (NULL);
	}
	return (tab);
}
