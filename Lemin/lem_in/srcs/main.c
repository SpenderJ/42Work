/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:41:16 by juspende          #+#    #+#             */
/*   Updated: 2018/02/07 12:17:42 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		main(void)
{
	t_s s;

	s.moves = NULL;
	if (input(&s) == -1 || find_moves(&s) == -1)
		return (QUIT);
	s.moves = list_moves_to_moves(&s.list_moves);
	sort_moves(s.moves, s.list_moves.nb_moves);
	print_lines(s.lines, s.nb_lines);
	print_moves(s.nodes, s.moves, s.list_moves.nb_moves);
	ft_printf("\n");
	free_all(&s.lines, &s.nodes, s.nb_nodes_expected, s.moves);
	return (SUCCESS);
}

int		input(t_s *s)
{
	s->lines.first = NULL;
	s->lines.last = NULL;
	get_input(&s->lines, &s->nb_nodes_expected);
	s->nodes = alloc_nodes(s->nb_nodes_expected);
	parse_lines(s);
	if (s->nb_ants < 0 || s->nodes[0].name == NULL || s->nodes[1].name == NULL)
	{
		free_all(&s->lines, &s->nodes, s->nb_nodes_expected, s->moves);
		return (ERROR_RETURN);
	}
	return (SUCCESS);
}

int		find_moves(t_s *s)
{
	int i;

	s->list_moves.first = NULL;
	s->list_moves.last = NULL;
	s->list_moves.nb_moves = 0;
	i = 0;
	while (++i <= s->nb_ants)
	{
		if (find_path(s->nodes, s->nb_nodes, &s->list_moves, i) == -1)
		{
			free_all(&s->lines, &s->nodes, s->nb_nodes_expected, s->moves);
			return (ERROR_RETURN);
		}
	}
	return (SUCCESS);
}

void	free_all(t_lines *lines, t_node **nodes, int nb_nodes_expected,
t_move *moves)
{
	if (lines)
		free_lines(lines);
	if (nodes && nb_nodes_expected)
		free_nodes(nodes, nb_nodes_expected);
	if (moves)
		free(moves);
}
