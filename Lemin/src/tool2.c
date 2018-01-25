/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:31:30 by juspende          #+#    #+#             */
/*   Updated: 2018/01/25 09:08:42 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_h.h"

int	list_len(t_tnl	*list)
{
	t_tnl	*tmp;
	int	i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->nxt;
		++i;
	}
	return (i);
}

void	free_ant(t_ant	*list)
{
	if (list)
	{
		free_ant(list->nxt);
		free(list);
	}
}

void	free_graph(t_graph	*list)
{
	if (list)
	{
		free_graph(list->nxt);
		free(list);
	}
}
