/*
** my_h.h for lem_in in /home/hecto/lem-in
** 
** Made by blaise carnevillier
** Login   <hecto@epitech.net>
** 
** Started on  Tue Apr 11 09:50:54 2017 blaise carnevillier
** Last update Sun Apr 30 17:31:27 2017 blaise carnevillier
*/

#ifndef _MY_H_
#define _MY_H_

# include <stdlib.h>
# include <unistd.h>
#include "../printf/include/ft_printf.h"

typedef struct	s_coord
{
  int		x;
  int		y;
}		t_coord;

typedef struct		s_graph
{
  char			*index;
  t_coord		*coord;
  struct s_tnl		*tunls;
  int			is_end;
  int			rank;
  int			is_start;
  int			is_full;
  struct s_graph	*nxt;
}			t_graph;

typedef struct	s_tnl
{
  t_graph	*dest;
  struct s_tnl	*nxt;
}		t_tnl;

typedef struct	s_ant
{
  int		nbr;
  t_graph	*node;
  struct s_ant	*nxt;
}		t_ant;

# define FALSE 0
# define TRUE !0

void	print_tnl(char*);

void	free_ant(t_ant*);

void	free_graph(t_graph*);

void	tell_me(t_ant*);

void	tell_list(t_graph*);

int	p_s(char*, int);

int	lets_play(t_ant*);

int	fb(char**);

int	my_printf(char*, ...);

int	at_oi(char*);

int	my_strcmp(char*, char*);

int	my_atoi(char*);

int	tablen(char**);

char	*get_next_line(int);

char	**my_str_to_wordtab(char *, char, int, int);

t_tnl	*add_tnl(t_tnl*, t_graph*);

t_ant	*add_start(t_ant*, t_graph*);

t_ant	*add_ant(t_ant*, int);

t_ant	*parsing_ant(t_ant*);

t_coord	*add_c(char*, char*);

t_graph	*get_end(t_graph*);

t_graph	*give_rank(t_graph *, int);

t_graph	*parsing_graph(t_graph*, int);

t_graph	*add_graph(t_graph*, char*, int, t_coord*);

t_graph	*add_tunnels(t_graph*, char*);

#endif /* !_MY_H_ */
