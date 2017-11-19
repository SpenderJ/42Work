/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:33:47 by juspende          #+#    #+#             */
/*   Updated: 2017/11/12 16:15:01 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

void		get_my_letters(char ***tab)
{
	int		i;
	int		n;
	char	c;

	i = 0;
	n = 0;
	c = 'A';
	if (!tab || !tab[i])
		return ;
	while (tab[i] != NULL)
		make_letters(tab[i++], c++);
	tab[i] = NULL;
	return ;
}

void		make_letters(char **tab, char c)
{
	int		i;
	int		j;

	i = -1;
	while (tab[++i] != NULL)
	{
		j = -1;
		while (tab[i][++j] != '\0')
			if (tab[i][j] == '#')
				tab[i][j] = c;
	}
	return ;
}

char		**ft_clear_empty_line(char **tab, int size)
{
	int		i;
	int		n;
	char	**tab2;

	i = -1;
	if ((tab2 = malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (tab[++i] != NULL && empty_line(tab[i]) != 0)
		;
	n = 0;
	while (tab[i] != NULL && empty_line(tab[i]) == 0)
		tab2[n++] = ft_strdup(tab[i++]);
	tab2[n] = NULL;
	return (tab2);
}

char		**ft_clear_empty_column(char **tab, int size)
{
	int		min;
	int		max;
	char	**tab2;
	int		y;
	int		x;

	min = -1;
	if ((tab2 = malloc(sizeof(char *) * (size + 1))) == NULL)
		return (NULL);
	while (++min < size && empty_col(tab, min) != 0)
		;
	max = size + 1;
	while (--max > min && empty_col(tab, max) != 0)
		;
	y = -1;
	while (tab[++y] != NULL && (x = -1) == -1)
	{
		if ((tab2[y] = malloc(sizeof(char) * ((max - min) + 2))) == NULL)
			return (NULL);
		while (min + (++x) <= max)
			tab2[y][x] = tab[y][min + x];
		tab2[y][x] = '\0';
	}
	tab2[y] = NULL;
	return (tab2);
}

char		***clear_tabs(char ***tab)
{
	int		i;
	int		n;

	i = 0;
	if (!tab || !tab[0])
		return (NULL);
	while (tab[i] != NULL && tab[i][0] != NULL)
	{
		n = -1;
		while (tab[i][++n] != NULL)
			;
		tab[i] = ft_clear_empty_line(tab[i], n);
		tab[i] = ft_clear_empty_column(tab[i], n);
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
