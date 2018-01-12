/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:28:47 by juspende          #+#    #+#             */
/*   Updated: 2018/01/12 17:59:46 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# ifndef SORTED
#  define SORTED 0
# endif

# ifndef SUMM
#  define SUMM 0
# endif

# ifndef RANKED
#  define RANKED 0
# endif

# ifndef ERROR_RANKING
#  define ERROR_RANKING 1
# endif

# ifndef PUSHSWAP_ERROR
#  define PUSHSWAP_ERROR 1
# endif

# ifndef SIZE_ERROR
#  define SIZE_ERROR "Each number has to be between INT_MIN and INT_MAX, Exit"
# endif

# ifndef DOUBLE_ERROR
#  define DOUBLE_ERROR "Each number in argument has to be unique, Exit"
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

# ifndef KO_END
#  define KO_END "KO"
# endif

# ifndef B_SIZE
#  define B_SIZE 0
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

# ifndef INIT_NEG
#  define INIT_NEG 1
# endif

# ifndef RRA
#  define RRA 42
# endif

# ifndef RA
#  define RA 21
# endif

# ifndef COMMAND_ERROR
#  define COMMAND_ERROR "Wrong Command, use ./pushswap -h to display help. Exit"
# endif

# ifndef HELP_1
#  define HELP_1 "Checker Usage: ./pushswap [Int List] ...\n\nList of commands:"
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
# include "../../libft/libft.h"
# include "../../printf/include/ft_printf.h"

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
