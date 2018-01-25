/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:31:06 by juspende          #+#    #+#             */
/*   Updated: 2018/01/25 10:04:50 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_h.h"

t_graph		*get_end(t_graph *list)
{
	t_graph	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->is_end == 1)
			return (tmp);
		tmp = tmp->nxt;
	}
	return (NULL);
}

t_graph		*give_rank(t_graph *g, int i)
{
	t_tnl		*tmp2;
	t_graph	*tmp;

	tmp = g;
	tmp->rank = i;
	tmp2 = tmp->tunls;
	while (tmp2)
	{
		if (tmp2->dest->rank > i)
			give_rank(tmp2->dest, i + 1);
		tmp2 = tmp2->nxt;
	}
	return (g);
}
