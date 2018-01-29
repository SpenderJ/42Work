/*
** tool2.c for lemin in /home/hecto/CPE_2016_Lemin
** 
** Made by blaise carnevillier
** Login   <hecto@epitech.net>
** 
** Started on  Sun Apr 30 10:59:18 2017 blaise carnevillier
** Last update Sun Apr 30 11:09:51 2017 blaise carnevillier
*/

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
