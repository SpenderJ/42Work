/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:28:47 by juspende          #+#    #+#             */
/*   Updated: 2018/01/28 13:19:44 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef SIZE_ERROR
#  define SIZE_ERROR "Each number has to be between INT_MIN and INT_MAX, Exit"
# endif

# ifndef DOUBLE_ERROR
#  define DOUBLE_ERROR "Error in int_list, Exit"
# endif

# ifndef PARSING_ERROR
#  define PARSING_ERROR "Parsing Error, Checker only accept numbers as argument"
# endif

# ifndef MALLOC_FAILED
#  define MALLOC_FAILED "Memory Allocation Failed, Exit of Checker"
# endif

# ifndef ARGUMENT_ERROR
#  define ARGUMENT_ERROR "Cant Open Arguments, Exit of Checker"
# endif

# ifndef OK_END
#  define OK_END "OK"
# endif

# ifndef I
#  define I 2147483647
# endif

# ifndef KO_END
#  define KO_END "KO"
# endif

# ifndef B_SIZE
#  define B_SIZE 0
# endif

# ifndef A_E
#  define A_E -30071998
# endif

# ifndef ENDOFARGS
#  define ENDOFARGS 30071998
# endif

# ifndef WRONG_ARG
#  define WRONG_ARG 84
# endif

# ifndef NO_ERROR
#  define NO_ERROR 0
# endif

# ifndef COMMAND_ERROR
#  define COMMAND_ERROR "Wrong Command, use ./checker -h to display help. Exit"
# endif

# ifndef HELP_1
#  define HELP_1 "Checker Usage: ./checker [Int List] ...\n\nList of commands:"
# endif

# ifndef HELP_2
#  define HELP_2 "\n\tsa\n\tsb\n\tss\n\tpa\n\tpb\n\tra\n\trb\n\trr\n\trra\n\t"
# endif

# ifndef HELP_3
#  define HELP_3 "rrb\n\trrr\n\nTo have informations about each command->intra"
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include "get_next_line.h"
# include "../../libft/libft.h"
# include "../../printf/include/ft_printf.h"
# include "../../free_all/include/ft_freeall.h"

int		main(int argc, char **argv);
void	sa(int *a_list);
void	sb(int *b_list);
void	ss(int *a_list, int *b_list);
void	pa(int *a_list, int *b_list);
void	pb(int *a_list, int *b_list);
void	ra(int *a_list);
void	rb(int *b_list);
void	rr(int *a_list, int *b_list);
void	rra(int *a_list);
void	rrb(int *b_list);
void	rrr(int *a_list, int *b_list);

#endif
