/*
** tool.c for lemin in /home/david.xu/Projet/CPE/CPE_2016_Lemin/src
** 
** Made by david xu
** Login   <david.xu@epitech.net>
** 
** Started on  Sat Apr 15 13:38:49 2017 david xu
** Last update Sun Apr 30 10:39:11 2017 blaise carnevillier
*/

#include <stdlib.h>
#include "my_h.h"

int     my_strcmp(char *str, char *str2)
{
  int	i;

  i = 0;
  while (str[i] != 0 && str2[i] != 0)
    {
      if (str[i] != str2[i])
	return (1);
      i++;
    }
  if (str[i] != 0 || str2[i] != 0)
    return (1);
  else
    return (0);
}

int	at_oi(char *str)
{
  int	nbr;
  int	i;
  int	s;

  i = 0;
  nbr = 0;
  if (str[i] == '-')
    {
      s = -1;
      ++i;
    }
  else
    s = 1;
  while (str[i] != 0 && str[i] != '\n')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      nbr = nbr * 10 + (str[i] - 48);
      ++i;
    }
  return (nbr * s);
}

int	tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  return (i);
}

int	p_s(char *str, int i)
{
  int	y;

  if (i == 1)
    my_printf("##start\n");
  else
    my_printf("##end\n");
  y = 0;
  while (str[y] != 0 && str[y] != '#')
    {
      my_printf("%c", str[y]);
      ++y;
    }
  write(1, "\n", 1);
  return (0);
}

int     fb(char **tab)
{
  int   i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i += 1;
    }
  return (0);
}
