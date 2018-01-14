/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:30:00 by juspende          #+#    #+#             */
/*   Updated: 2017/12/21 17:35:06 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_h.h"

t_coord		*add_c(char *x, char *y)
{
  t_coord	*new;

  if (!(new = malloc(sizeof(t_coord))))
    return (NULL);
  if ((new->x = at_oi(x)) == - 1)
    return (NULL);
  if ((new->y = at_oi(y)) == -1)
    return (NULL);
  return (new);
}

t_ant		*add_ant(t_ant *list, int nbr)
{
  t_ant		*newlist;

  if (!(newlist = malloc(sizeof(t_ant))))
    return (NULL);
  newlist->nbr = nbr;
  newlist->nxt = list;
  return (newlist);
}

t_graph		*add_graph(t_graph *list, char *str, int i, t_coord *xy)
{
  int		y;
  t_graph	*newlist;

  y = -1;
  if (!(newlist = malloc(sizeof(t_graph))) || xy == NULL)
      return (NULL);
  if (!(newlist->index = malloc(sizeof(str) + 1000)))
    return (NULL);
  while (str[++y] != 0)
    newlist->index[y] = str[y];
  newlist->index[y] = '\0';
  newlist->is_end = 0;
  newlist->rank = 28071995;
  newlist->is_start = 0;
  if (i == 1)
    newlist->is_end = 1;
  else if (i == 2)
    {
      newlist->is_full = 1;
      newlist->is_start = 1;
    }
  newlist->nxt = list;
  newlist->coord = xy;
  return (newlist);
}

t_graph		*new_tunnel(t_graph *for_graph, char *src, char *dest)
{
  t_graph	*tmp;
  t_graph	*tmp2;

  tmp = for_graph;
  tmp2 = for_graph;
  while (tmp && my_strcmp(tmp->index, src) == 1)
    tmp = tmp->nxt;
  if (!tmp)
    return (NULL);
  while (tmp2 && my_strcmp(tmp2->index, dest) == 1)
    tmp2 = tmp2->nxt;
  if (!tmp2)
    return (NULL);
  if (!(tmp->tunls = add_tnl(tmp->tunls, tmp2)))
    return (NULL);
  return (for_graph);
}

t_graph         *add_tunnels(t_graph *for_graph, char *str)
{
  char		**tab;

  while (str)
    {
      if (str[0] != '#')
	{
	  if (!(tab = my_str_to_wordtab(str, '-', 0, 0)))
	    return (NULL);
	  if (!tab[0] || !tab[1])
	    return (NULL);
	  if (!(for_graph = new_tunnel(for_graph, tab[0], tab[1])))
	    return (NULL);
	  if (!(for_graph = new_tunnel(for_graph, tab[1], tab[0])))
	    return (NULL);
	}
      print_tnl(str = get_next_line(0));
    }
  return (for_graph);
}
