/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tabtab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 17:01:43 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 16:31:32 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Fonctions de la LIBFT :
** -> ft_strdup. (importée ci dessous)
** -> ft_strdel. (importée ci dessous)
**
** Appel systeme :
** -> #include <stdlib> (pour malloc et NULL, free)
**
** Description :
** Cette fonction (ft_malloc_tabtab) permet d ajouter la ligne passée en
** second parametre sur le char ** passé en premier parametre.
** Si ce dernier n existe pas, il est créé et la str est fraîchement
** allouée a *tab.
*/

/*
** ***************************************
** START - Fonctions de libft importées. |
** ***************************************
*/

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

/*
** **************************************
** END - Fonctions de libft importées.  |
** **************************************
*/

static char	**ft_create(int size_y, char **tab, char *str)
{
	if (!(tab = (char **)malloc(sizeof(char *) * (size_y + 1))))
		return (NULL);
	tab[0] = str ? ft_strdup(str) : NULL;
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
