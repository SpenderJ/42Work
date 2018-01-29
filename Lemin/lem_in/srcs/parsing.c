/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:47:25 by juspende          #+#    #+#             */
/*   Updated: 2018/01/29 12:06:14 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_ant		*parsing_ant(t_ant *for_ants)
{
	int		max_ants;
	int		i;
	char	*str;

	get_next_line(0, &str);
	if (!str)
		return (NULL);
	if ((max_ants = ft_atoi(str)) < 0)
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

t_graph		*special(t_graph *list, char *str)
{
	char	*tmp;
	char	**t;

	if (ft_strcmp(str, "##start") == 0)
	{
		get_next_line(0, &tmp);
		if (!tmp)
			return (list);
		p_s(tmp, 1);
		if (!(t = ft_strsplit(tmp, ' ')))
			return (NULL);
		if (!(list = add_graph(list, t[0], 2, add_c(t[1], t[2]))))
			return (NULL);
	}
	else if (ft_strcmp(str, "##end") == 0 && get_next_line(0, &tmp) > 0)
	{
		if (!tmp)
			return (list);
		p_s(tmp, 0);
		if (!(t = ft_strsplit(tmp, ' ')))
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
	if (ft_tablen(tab = ft_strsplit(str, '-')) == 2)
		ft_printf("#tunnels\n");
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
	if (ft_tablen(tab = ft_strsplit(str, ' ')) <= 2 &&
			ft_tablen(tab = ft_strsplit(str, ' ')) > 3)
		return (NULL);
	return (tab);
}

t_graph	*parsing_graph(t_graph *for_graph, int	i)
{
	char	*str;
	char	**t;

	if (get_next_line(0, &str) < 0)
		return (NULL);
	if (!(t = get_tab(str)))
		return (NULL);
	while (str && i == 0)
	{
		if (str[0] == '#')
			for_graph = special(for_graph, str);
		else
		{
			if (fb(t) == 0 && ft_tablen(t = ft_strsplit(str, ' ')) <= 1)
				i = 1;
			else if (t[0] && t[1] && t[2])
				for_graph = add_graph(for_graph, t[0], 0, add_c(t[1], t[2]));
			else
				return (NULL);
		}
		if (i == 0 && get_next_line(0, &str) > 0)
			if ((print_str(str) == 84))
				return (NULL);
	}
	return (add_tunnels(for_graph, str));
}
