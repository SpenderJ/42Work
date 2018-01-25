/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:30:50 by juspende          #+#    #+#             */
/*   Updated: 2018/01/25 09:07:35 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "my_h.h"

t_ant	*parsing_ant(t_ant *for_ants)
{
	int	max_ants;
	int	i;
	char	*str;

	if ((str = get_next_line(0)) == NULL)
		return (NULL);
	if ((max_ants = at_oi(str)) < 0)
		return (NULL);
	ft_printf("#number_of_ants\n%d\n#rooms\n", i = max_ants);
	while (i > 0)
	{
		if (!(for_ants = add_ant(for_ants, i)))
			return (NULL);
		i -= 1;
	}
	return (for_ants);
}

t_graph	*special(t_graph *list, char *str)
{
	char	*tmp;
	char	**t;

	if (my_strcmp(str, "##start") == 0)
	{
		if ((tmp = get_next_line(0)) == NULL)
			return (list);
		p_s(tmp, 1);
		if (!(t = my_str_to_wordtab(tmp, ' ', 0, 0)))
			return (NULL);
		if (!(list = add_graph(list, t[0], 2, add_c(t[1], t[2]))))
			return (NULL);
	}
	else if (my_strcmp(str, "##end") == 0)
	{
		if ((tmp = get_next_line(0)) == NULL)
			return (list);
		p_s(tmp, 0);
		if (!(t = my_str_to_wordtab(tmp, ' ', 0, 0)))
			return (NULL);
		if (!(list = add_graph(list, t[0], 1, add_c(t[1], t[2]))))
			return (NULL);
	}
	return (list);
}

int	print_str(char *str)
{
	char	**tab;
	int	i;

	i = 0;
	if (!str)
		return (84);
	if (tablen(tab = my_str_to_wordtab(str, '-', 0, 0)) == 2)
		ft_printf("#tunnels\n", str);
	while (str[i] != '\0' && str[i] != '#')
	{
		write(1, &str[i], 1);
		++i;
	}
	if (i != 0)
		write(1, "\n", 1);
	return (0);
}

char	**get_tab(char *str)
{
	char	**tab;

	print_str(str);
	if (tablen(tab = my_str_to_wordtab(str, ' ', 0, 0)) <= 2 &&
			tablen(tab = my_str_to_wordtab(str, ' ', 0, 0)) > 3)
		return (NULL);
	return (tab);
}

t_graph	*parsing_graph(t_graph *for_graph, int	i)
{
	char	*str;
	char	**tab;

	if ((str = get_next_line(0)) == NULL)
		return (NULL);
	if (!(tab = get_tab(str)))
		return (NULL);
	while (str && i == 0)
	{
		if (str[0] == '#')
			for_graph = special(for_graph, str);
		else
		{
			if (fb(tab) == 0 && tablen(tab = my_str_to_wordtab(str, ' ', 0, 0)) <= 1)
				i = 1;
			else if (tab[0] && tab[1] && tab[2])
				for_graph = add_graph(for_graph, tab[0], 0, add_c(tab[1], tab[2]));
			else
				return (NULL);
		}
		if (i == 0)
			if ((print_str(str = get_next_line(0)) == 84))
				return (NULL);
	}
	return (add_tunnels(for_graph, str));
}
