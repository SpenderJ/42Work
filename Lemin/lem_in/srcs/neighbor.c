/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:22:47 by juspende          #+#    #+#             */
/*   Updated: 2018/02/06 16:51:20 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_neighbor	*alloc_neighbor(void)
{
	t_neighbor *neighbor;

	neighbor = malloc(sizeof(t_neighbor));
	neighbor->next = NULL;
	return (neighbor);
}

void		add_neighbor(t_neighbor **neighbors, int i_neighbor)
{
	t_neighbor *neighbor;

	neighbor = alloc_neighbor();
	neighbor->i_node = i_neighbor;
	neighbor->next = *neighbors;
	*neighbors = neighbor;
}

void		free_neighbors(t_neighbor **neighbors)
{
	t_neighbor *neighbor;
	t_neighbor *next;

	neighbor = *neighbors;
	while (neighbor != NULL)
	{
		next = neighbor->next;
		if (neighbor)
			free(neighbor);
		neighbor = next;
	}
	*neighbors = NULL;
}
