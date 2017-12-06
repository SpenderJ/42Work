/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:28:47 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 18:47:54 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# ifndef WRONG_INPUT
#  define WRONG_INPUT "TO BE CONFIGURED GROS FDP"
# endif

# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libft/libft.h"

typedef struct	s_info
{
	int		player;
	int		letter;
	int		ymap;
	int		xmap;
	char	**map;
}				t_info;

typedef struct	s_piece
{
	int		ypiece;
	int		xpiece;
	int		y;
	int		x;
	char	**piece;
}				t_piece;

int		main(void);
void	ft_get_piece(t_piece *piece);
void	ft_get_map(t_info *info);
int		play_1(t_info *info, t_piece *piece);
int		play_2(t_info *info, t_piece *piece);
void	ft_info_player(t_info *info);
void	ft_info_letter(t_info *info);
void	ft_info_xy(t_info *info);
void	fill_info_struct(t_info *info);

#endif
