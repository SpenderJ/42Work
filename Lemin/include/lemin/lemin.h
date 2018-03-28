/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:51:54 by juspende          #+#    #+#             */
/*   Updated: 2018/03/21 15:11:47 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_LEMIN_H
# define LEMIN_LEMIN_H

# include "vertex.h"

# define OPT_VERB (1 << 0)
# define OPT_STEP (1 << 1)
# define OPT_NGUI (1 << 2)

typedef struct	s_lemin
{
	char const	*prg;
	int			input;
	int			output;
	int			options;
	t_sds		map;
	int			ants;
	t_vertex	*start;
	t_vertex	*end;
}				t_lemin;

extern int		lemin_error(t_lemin *lemin, char const *fmt, ...);
extern int		lemin_valid(t_lemin *l, t_map *graph);

#endif
