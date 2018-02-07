/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:22:38 by juspende          #+#    #+#             */
/*   Updated: 2018/02/06 16:51:00 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_move	*list_moves_to_moves(t_list_moves *list_moves)
{
	t_list_move	*list_move;
	t_move		*moves;
	int			i;

	moves = malloc(list_moves->nb_moves * sizeof(t_move));
	list_move = list_moves->first;
	i = 0;
	while (list_move != NULL)
	{
		moves[i] = list_move->move;
		list_move = list_move->next;
		i++;
	}
	free_list_moves(list_moves);
	return (moves);
}

void	sort_moves(t_move *moves, int nb_moves)
{
	int		i1;
	int		i2;
	t_move	t;

	i1 = 1;
	while (i1 < nb_moves)
	{
		i2 = i1;
		while (i2 > 0 && moves[i2 - 1].time > moves[i2].time)
		{
			t = moves[i2 - 1];
			moves[i2 - 1] = moves[i2];
			moves[i2] = t;
			i2--;
		}
		i1++;
	}
}

void	print_moves(t_node *nodes, t_move *moves, int nb_moves)
{
	int i;
	int time;

	i = 0;
	time = -1;
	while (i < nb_moves)
	{
		if (moves[i].time > time)
			ft_printf("\n");
		else
			ft_printf(" ");
		time = moves[i].time;
		ft_printf("L%d-%s", moves[i].ant, nodes[moves[i].destination].name);
		i++;
	}
}
