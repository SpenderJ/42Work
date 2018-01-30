/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 17:14:51 by juspende          #+#    #+#             */
/*   Updated: 2018/01/30 13:16:00 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include "get_next_line.h"
# include "../../libft/libft.h"
# include "../../printf/include/ft_printf.h"
# include "../../free_all/include/ft_freeall.h"

/* Use of errno lib
*/

# ifndef ERROR
#  define ERROR 1000
# endif

/* Defines
*/

# ifndef MA_DEF
#  define MA_DEF 1000
# endif

# ifndef ATOI_ERROR
#  define ATOI_ERROR -30071998
# endif

# ifndef ERROR_PARSING
#  define ERROR_PARSING 0
# endif

# ifndef ERROR_RETURN
#  define ERROR_RETURN -1
# endif

# ifndef EOL
#  define EOL '\0'
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE !0
# endif

# ifndef COMMENT
#  define COMMENT '#'
# endif

# ifndef ERROR_STATEMENT
#  define ERROR_STATEMENT 84
# endif

/* Structs
*/

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_graph
{
	char			*index;
	t_coord			*coord;
	struct s_tnl	*tunls;
	int				is_end;
	int				rank;
	int				is_start;
	int				is_full;
	struct s_graph	*nxt;
}					t_graph;

typedef struct		s_tnl
{
	t_graph			*dest;
	struct s_tnl	*nxt;
}					t_tnl;

typedef struct		s_ant
{
	int				nbr;
	t_graph			*node;
	struct s_ant	*nxt;
}					t_ant;

/* Functions
*/

int			list_len(t_tnl *list);
void		free_ant(t_ant *list);
void		free_graph(t_graph *list);
void		print_tnl(char*);
void		free_ant(t_ant*);
void		free_graph(t_graph*);
void		tell_me(t_ant*);
void		tell_list(t_graph*);
int			p_s(char*, int);
int			lets_play(t_ant*);
int			fb(char**);
t_tnl		*add_tnl(t_tnl*, t_graph*);
t_ant		*add_start(t_ant*, t_graph*);
t_ant		*add_ant(t_ant*, int);
t_ant		*parsing_ant(t_ant*);
t_coord		*add_c(char*, char*);
t_graph		*get_end(t_graph*);
t_graph		*give_rank(t_graph *, int);
t_graph		*parsing_graph(t_graph*, int);
t_graph		*add_graph(t_graph*, char*, int, t_coord*);
t_graph		*add_tunnels(t_graph*, char*);

#endif
