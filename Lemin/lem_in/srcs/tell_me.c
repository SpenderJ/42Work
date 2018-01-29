/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tell_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 12:10:01 by juspende          #+#    #+#             */
/*   Updated: 2018/01/29 12:13:32 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	tell_me(t_ant *caca)
{
	t_ant	*tmp;

	tmp = caca;
	while (tmp != NULL)
	{
		ft_printf("emplacement = %s\n", tmp->node->index);
		tmp = tmp->nxt;
	}
}

void	tell_list(t_graph *list)
{
	t_graph	*tmp;
	t_tnl		*tmp2;

	tmp = list;
	while (tmp)
	{
		ft_printf("index = %s  rank = %d\n", tmp->index, tmp->rank);
		tmp2 = tmp->tunls;
		while (tmp2)
		{
			ft_printf("\t\t%s", tmp2->dest->index);
			tmp2 = tmp2->nxt;
		}
		tmp = tmp->nxt;
	}
}
