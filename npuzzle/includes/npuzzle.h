/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:17:51 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 04:40:09 by juspende         ###   ########.fr       */
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

# ifndef MAX
#  define MAX 35
# endif

# ifndef ILLEGAL_MAP
#  define ILLEGAL_MAP "The map sent to the binary is not well formated"
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

#endif
