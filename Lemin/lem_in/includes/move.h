/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:19:07 by juspende          #+#    #+#             */
/*   Updated: 2018/02/06 13:19:09 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

typedef struct	s_move
{
	int ant;
	int destination;
	int time;
}				t_move;

typedef struct	s_list_move
{
	t_move				move;
	struct s_list_move	*next;
}				t_list_move;

typedef struct	s_list_moves
{
	t_list_move	*first;
	t_list_move	*last;
	int			nb_moves;
}				t_list_moves;

#endif
