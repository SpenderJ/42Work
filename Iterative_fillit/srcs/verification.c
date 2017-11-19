/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmalfroy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:46:58 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/11/12 00:48:13 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

static int		verif_char(char **tab)
{
	int			i;
	int			j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			if (tab[i][j] != '#' && tab[i][j] != '.')
				return (0);
		if (j != 4)
			return (0);
	}
	return (i == 4 ? 1 : 0);
}

static int		verif_bloc(char **tab)
{
	int			nbchar;
	int			i;
	int			j;
	int			contact;
	int			nbcontact;

	i = -1;
	nbchar = 0;
	nbcontact = 0;
	while (tab[++i] && (j = -1) == -1)
		while (tab[i][++j])
			if (tab[i][j] == '#' && (nbchar++) >= 0 && (contact = 0) == 0)
			{
				contact += (i <= 2 && tab[i + 1][j] == '#') ? 1 : 0;
				contact += (j <= 2 && tab[i][j + 1] == '#') ? 1 : 0;
				contact += (i >= 1 && tab[i - 1][j] == '#') ? 1 : 0;
				contact += (j >= 1 && tab[i][j - 1] == '#') ? 1 : 0;
				nbcontact += contact;
			}
	return ((nbchar == 4 && nbcontact >= 6) ? 1 : 0);
}

int				verification(t_bloc *bloc)
{
	if (ft_list_foreach(bloc, &verif_char) == 0 || ft_list_foreach(bloc,
				&verif_bloc) == 0)
		return (0);
	return (1);
}
