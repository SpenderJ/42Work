/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:23:15 by juspende          #+#    #+#             */
/*   Updated: 2018/02/06 16:52:09 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	parse_lines(t_s *s)
{
	t_line	*line;
	int		stop;
	int		part;
	int		cmd;

	s->nb_lines = 0;
	s->nb_ants = -1;
	s->nb_nodes = 2;
	line = s->lines.first;
	stop = 0;
	part = 0;
	cmd = 0;
	while (line != NULL && !stop)
	{
		if (!parse_sharp(s->nodes, line->str, &stop, &cmd))
			if (!parse_part0(&s->nb_ants, line->str, &stop, &part))
				if (!parse_part1(s, line->str, &part, &cmd))
					parse_part2(s->nodes, s->nb_nodes, line->str, &stop);
		if (!stop)
			s->nb_lines++;
		line = line->next;
	}
}

int		parse_sharp(t_node *nodes, char *str, int *stop, int *cmd)
{
	if (str[0] != '#')
		return (SUCCESS);
	else if (ft_strequ(str, "##start") == 1)
	{
		*cmd = 1;
		if (nodes[0].name != NULL)
			*stop = 1;
	}
	else if (ft_strequ(str, "##end") == 1)
	{
		*cmd = 2;
		if (nodes[1].name != NULL)
			*stop = 1;
	}
	return (1);
}

int		parse_part0(int *nb_ants, char *str, int *stop, int *part)
{
	if (*part != 0)
		return (SUCCESS);
	*nb_ants = ft_atoi(str);
	if (*nb_ants < 0)
		*stop = 1;
	*part = 1;
	return (1);
}

int		parse_part1(t_s *s, char *str, int *part, int *cmd)
{
	char **words;

	words = ft_strsplit(str, ' ');
	if (*part != 1 || words[0] == NULL || words[1] == NULL || words[2] == NULL)
	{
		free_words(words);
		*part = 2;
		return (SUCCESS);
	}
	if (name_to_index(s->nodes, s->nb_nodes, words[0]) == -1)
	{
		if (*cmd == 1)
			s->nodes[0].name = ft_strdup(words[0]);
		else if (*cmd == 2)
			s->nodes[1].name = ft_strdup(words[0]);
		else
			s->nodes[s->nb_nodes++].name = ft_strdup(words[0]);
	}
	free_words(words);
	*cmd = 0;
	return (1);
}

void	parse_part2(t_node *nodes, int nb_nodes, char *str, int *stop)
{
	char	**words;
	int		i_node1;
	int		i_node2;

	words = ft_strsplit(str, '-');
	i_node1 = name_to_index(nodes, nb_nodes, words[0]);
	i_node2 = name_to_index(nodes, nb_nodes, words[1]);
	free_words(words);
	if (i_node1 == -1 || i_node2 == -1)
		*stop = 1;
	else
	{
		add_neighbor(&nodes[i_node1].neighbors, i_node2);
		add_neighbor(&nodes[i_node2].neighbors, i_node1);
	}
}
