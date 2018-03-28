/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin/solve.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:46:24 by juspende          #+#    #+#             */
/*   Updated: 2018/03/21 18:11:25 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_SOLVE_H
# define LEMIN_SOLVE_H

# include "vertex.h"

struct s_lemin;

extern void		lemin_visit(struct s_lemin *lemin, t_vertex *v);
extern void		lemin_solve(struct s_lemin *lemin, t_map *graph, int ants);

#endif
