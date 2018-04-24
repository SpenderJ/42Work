/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:18:07 by vtennero          #+#    #+#             */
/*   Updated: 2018/04/24 11:43:40 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "../LIBFT/libft.h"
# include "../printf/include/ft_printf.h"

# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (2048)
# define MAGIC_NUMBER_SIZE 4
# define MAX_PLAYERS 4
# define MEM_SIZE				(8*1024)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define BUFF_SIZE (CHAMP_MAX_SIZE)

typedef struct      s_player
{
    int             number;
    int             n_override;
    char            *name;
    char            *comment;
    char            *instructions;
    int             len;
    struct s_player *next;
}                   t_player;

typedef struct      s_gen
{
    int             nb_players;
    int             dump;
    struct s_player *players;
}                   t_gen;

/*
** ------------------------- INNER PARSER -------------------------
*/
int                 check_name_header(char *arg);
char                *inner_parser(char *arg, int len);
/*
** ------------------------- OUTER PARSER -------------------------
*/
int                 is_valid_dump(t_gen *params, int n_arg, char **av);
int                 is_valid_player(char *arg);
int                 is_numbered_player(t_gen *params, int i, int n_arg, char **av);
/*
** ------------------------- PLAYER BUILDER -------------------------
*/
t_player            *init_players(t_gen *params, char **av, int n_arg);
t_player            *set_player_number(t_player *player, t_player *list, int n, int a);
/*
** ------------------------- VARIOUS UTILITIES -------------------------
*/
char		        *ft_b_strjoin_clr(char *a, char *b, int d, int len);
char		        *ft_b_strjoin(char *a, char *b, int len_a, int len_b);
char        	    *ft_strndup_c(const char *s1, int n);
void        	    *ft_memset(void *b, int c, size_t n);
void        	    *ft_bzero_degeu(void *b, size_t n);
void        	    ft_putchar(char c);
void        	    ft_putnbr(int nb);
int                 ft_b_strncmp(const char *s1, const char *s2, size_t n);

/*
** ------------------------- DEBUG -------------------------
*/
#include <stdio.h>

void	            print_params(t_gen *params);
void	            print_arg(char *arg, int len, int option);

#endif
