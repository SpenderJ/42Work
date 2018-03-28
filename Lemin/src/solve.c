/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:47:57 by juspende          #+#    #+#             */
/*   Updated: 2018/03/21 15:11:40 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin/solve.h"
#include "lemin/lemin.h"
#include "lemin/gui.h"

static t_vertex	*getmin(t_lemin *lemin, t_vertex *v)
{
	t_vertex	*min;
	t_vertex	**edge;
	t_vertex	**end;

	min = NULL;
	if (!(edge = ft_vecbeg(&v->edges)))
		return (min);
	--edge;
	end = ft_vecend(&v->edges);
	v->inpath = 1;
	while (++edge < end)
	{
		if ((*edge) != lemin->start &&
			(*edge) != lemin->end && !(*edge)->inpath)
			lemin_visit(lemin, *edge);
		if ((!(*edge)->occupied || (*edge) == lemin->end) &&
			(!min || (*edge)->dist <= min->dist) &&
			(*edge) != lemin->start && (*edge)->dist != UINT32_MAX)
			min = *edge;
	}
	v->inpath = 0;
	if (min && min->dist > v->dist && v != lemin->start)
		return (NULL);
	return (min);
}

static void		unvisit(t_map *graph)
{
	size_t		it;
	t_vertex	*v;

	it = 0;
	while (it < graph->cap)
		if (!(graph->bucks[it++] & BUCKET_BOTH))
		{
			v = (t_vertex *)graph->vals + it - 1;
			v->visited = 0;
		}
}

void			lemin_visit(t_lemin *lemin, t_vertex *v)
{
	t_vertex *path;

	if (!(path = getmin(lemin, v)))
		return ;
	if (!v->occupied || v->visited || (path->occupied && path != lemin->end))
		return ;
	if (lemin->options & OPT_VERB)
		ft_dprintf(lemin->output, "%d[%s(%d) > %s(%d)] ",
			v->occupied, v->id, v->dist, path->id, path->dist);
	else if (!(lemin->options & OPT_NGUI))
		ft_dprintf(lemin->output, "L%d-%s ", v->occupied, path->id);
	path->occupied = path == lemin->end ? path->occupied + 1 : v->occupied;
	path->visited = 1;
	v->occupied = 0;
	lemin_guidraw();
}

void			lemin_solve(t_lemin *lemin, t_map *graph, int ants)
{
	t_vertex **edge;
	t_vertex **end;

	if (lemin->end->occupied == lemin->ants)
		return ;
	edge = (t_vertex **)ft_vecbeg(&lemin->start->edges) - 1;
	end = ft_vecend(&lemin->start->edges);
	if (lemin->options & OPT_VERB)
		ft_dprintf(lemin->output, "ants: %d/%d\n", ants, lemin->ants);
	unvisit(graph);
	while (++edge < end)
		lemin_visit(lemin, *edge);
	if (ants < lemin->ants || lemin->start->occupied)
		while (1)
		{
			if (!lemin->start->occupied)
				lemin->start->occupied = ++ants;
			lemin_visit(lemin, lemin->start);
			if (lemin->start->occupied || ants >= lemin->ants)
				break ;
		}
	if (lemin->options & OPT_STEP && isatty(STDIN_FILENO))
		read(STDIN_FILENO, NULL, 1);
	!(lemin->options & OPT_NGUI) ? ft_dprintf(lemin->output, "\n") : 0;
	lemin_solve(lemin, graph, ants);
}
