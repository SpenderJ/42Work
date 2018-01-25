/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tell_me.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:31:12 by juspende          #+#    #+#             */
/*   Updated: 2018/01/25 09:07:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "my_h.h"

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
