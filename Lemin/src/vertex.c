/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:47:57 by juspende          #+#    #+#             */
/*   Updated: 2018/03/22 13:59:03 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin/vertex.h"

void	lemin_vertexctor(t_vertex *vertex)
{
	ft_bzero(vertex, sizeof(t_vertex));
	ft_vecctor(&vertex->edges, sizeof(t_vertex *));
	vertex->dist = UINT32_MAX;
}

void	lemin_vertexdtor(t_vertex *vertex)
{
	ft_vecdtor(&vertex->edges, NULL);
}

int		lemin_vertexadd(t_map *graph, t_vertex vertex)
{
	uint32_t it;

	if (!ft_mapput(graph, (void *)vertex.id, &it))
		return (NOP);
	((t_vertex *)graph->vals)[it] = vertex;
	return (YEP);
}

int		lemin_edged(t_vertex *a, t_vertex *b)
{
	t_vertex		**it;

	if ((it = ft_vecbeg(&a->edges)))
		while (it < (t_vertex **)ft_vecend(&a->edges))
		{
			if (!ft_strcmp((*it)->id, b->id))
				return (1);
			++it;
		}
	return (0);
}

int		lemin_edgeadd(t_map *graph, char const *from, char const *to)
{
	uint32_t	itf;
	uint32_t	itt;
	t_vertex	*vf;
	t_vertex	*vt;

	if (!ft_mapget(graph, (void *)from, &itf))
		return (NOP);
	if (!ft_mapget(graph, (void *)to, &itt))
		return (NOP);
	vf = (t_vertex *)graph->vals + itf;
	vt = (t_vertex *)graph->vals + itt;
	if (lemin_edged(vf, vt) || lemin_edged(vt, vf))
		return (OUF);
	*(t_vertex **)ft_vecpush(&vf->edges) = vt;
	return (YEP);
}
