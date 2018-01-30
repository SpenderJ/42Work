/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 11:34:49 by juspende          #+#    #+#             */
/*   Updated: 2018/01/30 13:57:33 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_tnl(char *str)
{
	int			i;

	i = 0;
	if (!str)
		i = 0;
	else
	{
		while (str[i] != 0 && str[i] != '#')
		{
			ft_printf("%s", &str[i]);
			++i;
		}
		if (i != 0)
			ft_printf("\n");
	}
}

t_tnl	*add_tnl(t_tnl	*list, t_graph *room)
{
	t_tnl		*tunel;

	if (!(tunel = malloc(sizeof(t_tnl))))
		return (NULL);
	tunel->dest = room;
	tunel->nxt = list;
	return (tunel);
}

t_ant	*add_start(t_ant *list, t_graph *room)
{
	t_graph		*tmp2;
	t_ant		*tmp;
	int			i;

	tmp = list;
	tmp2 = room;
	i = 0;
	while (tmp2 && i != 1)
	{
		if (tmp2->is_start == 1)
			i = 1;
		if (i != 1)
			tmp2 = tmp2->nxt;
	}
	if (i != 1)
		return (NULL);
	while (tmp)
	{
		tmp->node = tmp2;
		tmp = tmp->nxt;
	}
	return (list);
}
