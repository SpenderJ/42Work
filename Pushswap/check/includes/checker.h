/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:28:47 by juspende          #+#    #+#             */
/*   Updated: 2017/12/29 16:00:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef PARSING_ERROR
#  define PARSING_ERROR "Parsing Error, Checker only accept numbers as argument"
# endif

# ifndef MALLOC_FAILED
#  define MALLOC_FAILED "Memory Allocation Failed, Exit of Checker"
# endif

# ifndef ARGUMENT_ERROR
#  define ARGUMENT_ERROR "Cant Open Arguments, Exit of Checker"
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../../libft/libft.h"

int		main(int argc, char **argv);

#endif
