/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:17:30 by juspende          #+#    #+#             */
/*   Updated: 2018/04/24 13:26:58 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# include <stdlib.h>
/*
 * ** TODO: Add all others includes necessary
 * */

typedef struct	s_arena
{
	uint8_t		mem[MEM_SIZE];
	int32_t		cycle_to_die;
	int32_t		cycle_total;
}				t_arena;

#endif
