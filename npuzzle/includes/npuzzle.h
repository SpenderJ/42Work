/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:17:51 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 14:23:28 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H

# define NPUZZLE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# include "../libft/libft.h"
# include "../free_all/include/ft_freeall.h"
# include "../printf/include/ft_printf.h"

# ifndef NO_FILE_INPUT
#  define NO_FILE_INPUT "No file sent to the binary"
# endif

# ifndef NOT_SOLVABLE
#  define NOT_SOLVABLE "Unfortunately, your taquin can't be solved..."
# endif

# ifndef TOO_BIG
#  define TOO_BIG "You are not allowed to pass a map bigger than the MAX value which is defined in the npuzzle.h, thanks try an other map or change MAX value"
# endif

# ifndef ERROR_RESOLVING
#  define ERROR_RESOLVING "Unknown error during resolution, try again?"
# endif

# ifndef MAX
#  define MAX 12
# endif

# ifndef ADD
#  define ADD 1
# endif

# ifndef REMOVE
#  define REMOVE -1
# endif

# ifndef ILLEGAL_MAP
#  define ILLEGAL_MAP "The map sent to the binary is not well formated"
# endif

# ifndef UP
#  define UP 1
# endif

# ifndef RIGHT
#  define RIGHT 2
# endif

# ifndef DOWN
#  define DOWN 3
# endif

# ifndef LEFT
#  define LEFT 4
# endif

/*
 * If you want to toggle a special search, welcome here, my program is
 * made to use his 3 algorithms and evaluate the number of moves of each one
 * and propose you the best.
 *
 * Here you can choose your euristhic function to use, chnage SPECIFIC_SEARCH
 * value to:
 * 1- Hamming distance
 * 2- Gaschnig distance
 * 3- Manhattan distance
*/

# ifndef SPECIFIC_SEARCH
#  define SPECIFIC_SEARCH -1
# endif

int			main(int argc, char **argv);
int			handle_error(char *descriptor);
int			**npuzzle_parse(char *filename, int *size);
int			hamming_distance(int **map, int mapSize);
int			**npuzzle_solvedmap(int mapSize);
int			ft_print(int **map, int nb_col);
int			isSolved(int **map, int mapSize);
int			get0position(int *x, int *y, int **map, int mapSize);
int			get_last_op(int *moves);

#endif
