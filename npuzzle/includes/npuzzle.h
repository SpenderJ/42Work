/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npuzzle.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:17:51 by juspende          #+#    #+#             */
/*   Updated: 2019/03/29 03:56:03 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NPUZZLE_H

# define NPUZZLE_H

#include <unistd.h>
#include <stdlib.h>
# include "../libft/libft.h"
# include "../free_all/include/ft_freeall.h"
# include "../printf/include/ft_printf.h"

# ifndef NO_FILE_INPUT
#  define NO_FILE_INPUT "No file sent to the binary"
# endif

# ifndef ILLEGAL_MAP
#  define ILLEGAL_MAP "The map sent to the binary is not well formated"
# endif

int			main(int argc, char **argv);
int			handle_error(char *descriptor);
int			**npuzzle_parse(char *filename, int *size);

#endif
