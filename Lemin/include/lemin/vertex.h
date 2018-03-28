/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin/vertex.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 10:46:24 by alucas-           #+#    #+#             */
/*   Updated: 2018/03/21 20:02:08 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_VERTEX_H
# define LEMIN_VERTEX_H

# include <libft.h>

enum			e_vertex
{
	VERTEX_NONE,
	VERTEX_START,
	VERTEX_END
};

typedef struct	s_vertex
{
	uint8_t		kind;
	char		*id;
	int			x;
	int			y;
	t_vec		edges;
	int			inpath;
	int			visited;
	int			occupied;
	size_t		dist;
}				t_vertex;

/*
** Construct a `vertex`.
** @param vertex   The vertex to initialize
*/
extern void		lemin_vertexctor(t_vertex *vertex);

/*
** Deconstruct a `vertex`.
** Does not free the vertex id, it will be freed on the vertex hash map
** deconstruction.
** @param vertex  The vertex to destroy
*/
extern void		lemin_vertexdtor(t_vertex *vertex);

/*
** Try to add a `vertex` to the `vertex` hash map.
** @param vertex  The vertex hash map
** @param vertex  The vertex to add
** @return       `NOP`(1) if already exists, `YEP`(0) otherwise
*/
extern int		lemin_vertexadd(t_map *graph, t_vertex vertex);

/*
** Try to edge two vertex using there ids.
** @param vertex The vertex hash map
** @param from   The from vertex id to edge
** @param to     The to vertex id to edge
** @return       `NOP`(1) if already one the ids `from` or `to` does not exists
**               in the `vertex`, `OUF`(2) on duplicate edges `YEP`(0) otherwise
*/
extern int		lemin_edgeadd(t_map *graph, char const *from, char const *to);

/*
** Check if two vertex `a` and `b` are connected or not.
** @param a      The vertex a
** @param b      The vertex b
** @return       (1) if connected, (0) otherwise
*/
extern int		lemin_edged(t_vertex *a, t_vertex *b);

#endif
