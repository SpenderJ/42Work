/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_builder_set_number.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:46:35 by juspende          #+#    #+#             */
/*   Updated: 2018/04/24 12:56:21 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

t_player		*add_player_to_list(t_player *new, t_player *list)
{
	t_player	*tmp;

	tmp = list;
	if (!list)
		list = new;
	else
	{
		while (tmp)
			tmp = tmp->next;
		new->next = list;
		list = new;
	}
	return (list);
}

int				check_if_value_taken(t_player *list, int n)
{
	t_player	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->number == n)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_player		*reassign_player(t_player *to_reassign, t_player *list, int value)
{
	int			n;

	n = 1;
	to_reassign->number = -1;
	while (1)
	{
		if (n == value || check_if_value_taken(list, n))
			n++;
		else
		{
			to_reassign->number = n;
			return (list);
		}
	}
	return (NULL);
}

t_player		*set_player_number(t_player *player, t_player *list, int n, int a)
{
	t_player	*tmp;

	tmp = list;
	player->n_override = (a == 1) ? 1 : 0;
	while (tmp)
	{
		if (a == 1 && tmp->number == n && tmp->n_override == 1)
			return (NULL);
		else if (a == 1 && tmp->number == n)
			list = reassign_player(tmp, list, n);
		else if (a == 0 && tmp->number == n)
			return(set_player_number(player, list, n + 1, 0));
		tmp = tmp->next;
	}
	player->number = n;
	return (add_player_to_list(player, list));
}
