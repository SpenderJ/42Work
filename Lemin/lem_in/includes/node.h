/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:19:14 by juspende          #+#    #+#             */
/*   Updated: 2018/02/06 13:19:17 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

typedef struct	s_neighbor
{
	int					i_node;
	struct s_neighbor	*next;
}				t_neighbor;

typedef struct	s_node
{
	char		*name;
	t_neighbor	*neighbors;
	int			time_available;
	int			reached;
	int			time_reach;
	int			previous;
}				t_node;

#endif
