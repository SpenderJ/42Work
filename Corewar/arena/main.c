/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:11:52 by juspende          #+#    #+#             */
/*   Updated: 2018/04/11 15:28:24 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "arena.h"
# include "../includes/op.h"
# include "../LIBFT/libft.h"

static t_arena	g_arena_stack;
t_arena			*g_arena = &g_arena_stack;

int		main(int ac, char **av)
{
	ft_bzero(g_arena, sizeof(t_arena));
	return (0);
}
