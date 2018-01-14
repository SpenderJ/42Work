/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:30:08 by juspende          #+#    #+#             */
/*   Updated: 2017/12/21 17:30:12 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_h.h"

void	print_tnl(char *str)
{
  int	i;

  i = 0;
  if (!str)
    i = 0;
  else
    {
      while (str[i] != 0 && str[i] != '#')
	{
	  write(1, &str[i], 1);
	  ++i;
	}
      if (i != 0)
	write(1, "\n", 1);
    }
}

t_tnl	*add_tnl(t_tnl	*list, t_graph *room)
{
  t_tnl	*tunel;

  if (!(tunel = malloc(sizeof(t_tnl))))
    return (NULL);
  tunel->dest = room;
  tunel->nxt = list;
  return (tunel);
}

t_ant		*add_start(t_ant *list, t_graph *room)
{
  t_graph	*tmp2;
  t_ant		*tmp;
  int		i;

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
