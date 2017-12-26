/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:28:47 by juspende          #+#    #+#             */
/*   Updated: 2017/12/26 12:19:56 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# ifndef WRONG_INPUT
#  define WRONG_INPUT "TO BE CONFIGURED GROS FDP"
# endif

# ifndef ATTACK_SUCCESS_TIME_TO_LAUNCH_THE_NEW_MAP
#  define ATTACK_SUCCESS_TIME_TO_LAUNCH_THE_NEW_MAP 1
# endif

# ifndef KEEP_GOING
#  define KEEP_GOING 0
# endif

# ifndef NUM_DEC
#  define NUM_DEC 4
# endif

# ifndef P1
#  define P1 'O'
# endif

# ifndef P2
#  define P2 'X'
# endif

# ifndef SUCCESS
#  define SUCCESS 1
# endif

# ifndef FAIL
#  define FAIL 0
# endif

# ifndef OPPON_CHAR
#  define OPPON_CHAR(Value) (Value == 'O' ? 'O' : 'C')
# endif

# ifndef KEEP_GOING
#  define KEEP_GOING 0
# endif

# ifndef UPLEFT
#  define UPLEFT 0
# endif

# ifndef UPRIGHT
#  define UPRIGHT 2
# endif

# ifndef DOWNRIGHT
#  define DOWNRIGHT 1
# endif

# ifndef DOWNLEFT
#  define DOWNLEFT 3
# endif

# ifndef MAJ
#  define MAJ 32
# endif

# ifndef FREE_SPACE
#  define FREE_SPACE '*'
# endif

# ifndef ONE_OR_NOTHING
#  define ONE_OR_NOTHING(Value) (Value == 1 ? 1 : 0)
# endif

# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_info
{
	int		player;
	char	letter;
	char	letter_enemy;
	int		finalx;
	int		finaly;
	int		ymap;
	int		xmap;
	char	**map;
	int		end;
	int		attack;
}				t_info;

typedef struct	s_piece
{
	int		ypiece;
	int		xpiece;
	int		y;
	int		x;
	int		x_enemy;
	int		y_enemy;
	char	**piece;
}				t_piece;

//void	init_struct(t_info *info, t_piece *piece);
int		main(void);
void	initialize_algo(t_info *info, t_piece *piece, int i, int j);
void	set_values(int i, int j, t_info *info, t_piece *piece);
int		ft_printf(const char *list, ...);
void	attack_swap(t_info *info);
void	send_info(t_info *info);
int		algo(t_info *info, t_piece *piece);
int		try_value(t_piece *piece, t_info *info, int i, int j);
void	ft_get_piece(t_piece *piece);
void	ft_get_map(t_info *info, t_piece *piece);
int		play_1(t_info *info, t_piece *piece);
int		play_2(t_info *info, t_piece *piece);
void	ft_info_player(t_info *info);
void	ft_info_letter(t_info *info);
void	ft_info_xy(t_info *info);
void	fill_info_struct(t_info *info);

#endif
