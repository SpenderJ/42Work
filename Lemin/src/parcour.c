/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:30:41 by juspende          #+#    #+#             */
/*   Updated: 2018/01/25 09:07:21 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_h.h"

int	is_finished(t_ant *a)
{
	t_ant	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->node->is_end == 1)
			tmp = tmp->nxt;
		else
			return (1);
	}
	free(tmp);
	return (0);
}

t_graph		*min_rank(t_tnl *t)
{
	int		min;
	t_graph	*ret;
	t_tnl		*tmp;

	tmp = t;
	min = tmp->dest->rank;
	ret = tmp->dest;
	while (tmp)
	{
		if (tmp->dest->rank <= min && \
				(tmp->dest->is_full == 0 ||\
				 tmp->dest->is_end == 1))
		{
			ret = tmp->dest;
			min = tmp->dest->rank;
		}
		tmp = tmp->nxt;
	}
	return (ret);
}

t_ant		*move_ant(t_ant *a)
{
	t_ant		*tmp;
	t_graph	*new;

	tmp = a;
	new = min_rank(tmp->node->tunls);
	if (new->rank < tmp->node->rank && (\
				new->is_full == 0 ||
				new->is_end == 1))
	{
		tmp->node->is_full = 0;
		new->is_full = 1;
		tmp->node = new;
		ft_printf("P%d-%s ", tmp->nbr, tmp->node->index);
	}
	return (tmp);
}

int	lets_play(t_ant *a)
{
	t_ant	*tmp;
	int	i;

	i = 0;
	ft_printf("#moves\n");
	while (is_finished(a) && i < 1000000)
	{
		tmp = a;
		while (tmp)
		{
			tmp = move_ant(tmp);
			tmp = tmp->nxt;
		}
		i++;
		write(1, "\n", 1);
	}
	return (0);
}
