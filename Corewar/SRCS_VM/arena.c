/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:16:30 by juspende          #+#    #+#             */
/*   Updated: 2018/04/24 11:43:04 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/arena.h"
#include "../includes/op.h"
#include "../LIBFT/libft.h"

static t_arena	g_arena_stack;
t_arena			*g_arena = &g_arena_stack;

int		arena(int ac, char **av)
{
	(void)ac;
	(void)av;
	ft_bzero(g_arena, sizeof(t_arena));
	return (0);
}
