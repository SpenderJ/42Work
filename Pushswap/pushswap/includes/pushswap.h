/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:28:47 by juspende          #+#    #+#             */
/*   Updated: 2018/01/29 19:49:14 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

/*
**                          COMMANDS WRITING
**
**
** Here are the 11 commands that i'm allowed to use for this project
*/

# ifndef SA
#  define SA 1
# endif

# ifndef SB
#  define SB 2
# endif

# ifndef SS
#  define SS 3
# endif

# ifndef PA
#  define PA 4
# endif

# ifndef PB
#  define PB 5
# endif

# ifndef RA
#  define RA 6
# endif

# ifndef RB
#  define RB 7
# endif

# ifndef RR
#  define RR 8
# endif

# ifndef RRA
#  define RRA 9
# endif

# ifndef RRB
#  define RRB 10
# endif

# ifndef RRR
#  define RRR 11
# endif

/*
**                             END OF COMMAND LIST
** Now all macros are used in the code
*/

# ifndef SORTED
#  define SORTED 0
# endif

# ifndef LOW_SIZE_TO_SORT
#  define LOW_SIZE_TO_SORT 18
# endif

# ifndef MED_NUM
#  define MED_NUM 0
# endif

# ifndef A_E
#  define A_E -30071998
# endif

# ifndef EMPTY
#  define EMPTY 0
# endif

# ifndef SUMM
#  define SUMM 0
# endif

# ifndef RANKED
#  define RANKED 0
# endif

# ifndef S_ERR
#  define S_ERR 1
# endif

# ifndef NO_ERROR
#  define NO_ERROR 0
# endif

# ifndef ERROR
#  define ERROR 1
# endif

# ifndef ERROR_RANKING
#  define ERROR_RANKING 1
# endif

# ifndef PUSHSWAP_ERROR
#  define PUSHSWAP_ERROR 1
# endif

# ifndef INT_DONT_EXIST
#  define INT_DONT_EXIST -84
# endif

# ifndef SPLIT
#  define SPLIT 4
# endif

# ifndef BIG
#  define BIG 70
# endif

# ifndef ENDED
#  define ENDED -30071998
# endif

# ifndef I
#  define I 2147483647
# endif

# ifndef SIZE_ERROR
#  define SIZE_ERROR "Each number has to be between INT_MIN and INT_MAX, Exit"
# endif

# ifndef DOUBLE_ERROR
#  define DOUBLE_ERROR "Error in numbers in argument, Exit"
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

# ifndef SIZE
#  define SIZE 22000
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

# ifndef R
#  define R 21
# endif

# ifndef UNKNOWN_BUG
#  define UNKNOWN_BUG "Wow, this should have not happened... Program will exit"
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
# include "../../free_all/include/ft_freeall.h"
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
void	optimize_output(int *op);
int		list_sorted(int *a_list, int *b_list);
int		find_int_position(int *list, int to_find);
int		rr_r(int *a_list, int pos);
int		quick_solve(int *a_list);
int		ft_publish(int command);
int		free_pushswap(int *a_list, int *b_list, int ret);
int		ds(int *a_list, int *b_list, int *op);
int		ds2(int *a_list, int *b_list, int summ, int *op);
int		selective_sort(int *a_list, int *b_list, int *op);
int		rank_alist(int *a_list, int c, int n, int rank);
int		parse_again_with_medians2(int *a_list, int *b_list, int *med_table,
		int *op);
int		pushswap2(int *a_list, int *b_list, int c, int n);

#endif
