/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:47:57 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/22 13:58:39 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	verror(t_lemin *lemin, char const *fmt, va_list ap)
{
	if (lemin->options & OPT_VERB)
	{
		if (isatty(STDERR_FILENO))
			ft_fprintf(g_stderr, CLR_BRED"%s: "CLR_RESET, lemin->prg);
		else
			ft_fprintf(g_stderr, "%s: ", lemin->prg);
		ft_vfprintf(g_stderr, fmt, ap);
	}
	else
		ft_fprintf(g_stderr, "ERROR\n");
}

int			lemin_error(t_lemin *lemin, char const *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	verror(lemin, fmt, ap);
	va_end(ap);
	return (OUF);
}

static void	updatedist(t_lemin *lemin, size_t dist, t_vertex *v, t_vertex *prev)
{
	t_vertex **edge;
	t_vertex **end;

	if (prev == lemin->start || dist > 500 || !(edge = ft_vecbeg(&v->edges)))
		return ;
	if (v->dist > dist)
		v->dist = dist;
	else
		return ;
	if (v == lemin->start)
		return ;
	end = ft_vecend(&v->edges);
	while (edge < end)
	{
		if (!prev || *edge != prev)
			updatedist(lemin, dist + 1, *edge, v);
		++edge;
	}
}

static int	prepare(t_lemin *lemin, t_map *graph)
{
	size_t		it;
	t_vertex	*v;
	t_vertex	**edge;

	it = 0;
	while (it < graph->cap)
		if (!(graph->bucks[it++] & BUCKET_BOTH))
		{
			v = (t_vertex *)graph->vals + it - 1;
			if ((edge = ft_vecbeg(&v->edges)))
				while (edge < (t_vertex **)ft_vecend(&v->edges))
				{
					if (!lemin_edged(*edge, v))
						*(t_vertex **)ft_vecpush(&(*edge)->edges) = v;
					++edge;
				}
		}
	updatedist(lemin, 0, lemin->end, NULL);
	if (lemin->start->dist == UINT32_MAX || lemin->end->dist != 0)
		return (lemin_error(lemin, "Start and end room aren't linked\n"));
	return (YEP);
}

int			lemin_valid(t_lemin *l, t_map *graph)
{
	size_t		it;
	t_vertex	*v;

	it = 0;
	while (it < graph->cap)
		if (!(graph->bucks[it++] & BUCKET_BOTH))
		{
			if ((v = (t_vertex *)graph->vals + it - 1)->kind == VERTEX_START)
			{
				if (l->start)
					return (lemin_error(l, "Duplicate start `%s`\n", v->id));
				l->start = v;
			}
			else if (v->kind == VERTEX_END)
			{
				if (l->end)
					return (lemin_error(l, "Duplicate end `%s`\n", v->id));
				l->end = v;
			}
		}
	if (!l->start || !l->end)
		return (lemin_error(l, "No start/end rooms\n"));
	return (prepare(l, graph));
}
