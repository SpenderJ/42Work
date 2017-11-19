/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 02:16:13 by juspende          #+#    #+#             */
/*   Updated: 2017/11/12 19:09:13 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"
#include <stdlib.h>

int		rot(char *mot, int n, int k)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = mot[k];
	if (k == n)
		return (0);
	i = k - 1;
	while (++i < n - 1)
		mot[i] = mot[i + 1];
	mot[n - 1] = tmp;
	return (0);
}

int		fill_struct(const char *s, t_solution *solution)
{
	int		i;

	i = 0;
	while (solution->so[i] != NULL)
		++i;
	solution->so[i] = ft_strdup(s);
	if (i >= 1 && solution->so[i - 1][0] < solution->so[i][0])
		return (84);
	if ((i >= 1) && ft_strcmp(solution->so[i - 1], solution->so[i]) > 0)
	{
		solution->so[i - 1] = solution->so[i];
	}
	if (i == 0)
		solution->so[i + 1] = NULL;
	else
		solution->so[i] = NULL;
	return (0);
}

char	*generator(char *s, char ***tab, char **map, t_solution *solution)
{
	int			cur;
	int			*nb;
	int			n;
	static int	i = -1;

	n = ft_strlen(s);
	if ((nb = malloc(sizeof(int) * ft_strlen(s))) == NULL)
		return (NULL);
	while ((cur = n) == n && ++i < n)
		nb[i] = n - i - 1;
	while (cur != -1)
	{
		if (nb[cur] != 0 && (i = cur) == cur)
		{
			while (++i < n)
				nb[i] = n - i - 1;
			rot(s, n, cur);
			nb[cur]--;
			if (regen_map(s, map, tab) != 2 && success(map, solution->tetriminos) == 0)
				if (fill_struct(s, solution) == 84)
					return (s);
			cur = n - 1;
		}
		else
			rot(s, n, cur--);
	}
	free(nb);
	return (NULL);
}
