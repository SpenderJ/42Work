/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_str_to_wordtab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:30:34 by juspende          #+#    #+#             */
/*   Updated: 2017/12/21 17:30:37 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_h.h"

int     my_cntchar(char *str, char c)
{
  int   i;

  i = 0;
  while ((str[i] != c) && (str[i] != '\0') && (str[i] != '\n'))
    i++;
  return (i + 1);
}

int     my_cntword(char *str, char c)
{
  int   i;
  int   res;

  i = -1;
  res = 1;
  while (str[++i] != '\0' && str[i] != '\n')
    if (str[i] == c && str[i + 1] != '\0')
      res++;
  return (res);
}

char    **my_str_to_wordtab(char *str, char c, int x, int y)
{
  char  **tab;
  int	i;

  i = 0;
  if ((tab = malloc(sizeof(char*) * ((my_cntword(str, c) + 1)))) == NULL)
    return (NULL);
  while (str[i] == ' ' && str[i++] != '\0');
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == c || str[i] == '\n')
        {
          while (str[i] == c || str[i] == ' ')
            i++;
          x += 1;
          y = 0;
        }
      if (!(tab[x] = malloc(sizeof(char*) * ((my_cntchar(str + i, c) + 1)))))
        return (NULL);
      while ((str[i] != c)  && (str[i] != '\n') && (str[i] != '\0'))
        tab[x][y++] = str[i++];
      tab[x][y] = '\0';
    }
  tab[x + 1] = 0;
  return (tab);
}
