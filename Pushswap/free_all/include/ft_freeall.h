/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeall.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 18:39:28 by juspende          #+#    #+#             */
/*   Updated: 2018/01/29 19:02:38 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FREEALL_H
# define FT_FREEALL_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>
# include <fcntl.h>

# ifndef INT
#  define INT 'a'
# endif

# ifndef CHAR
#  define CHAR 'b'
# endif

# ifndef CHARR
#  define CHARR 'c'
# endif

# ifndef END
#  define END 0
# endif

int		ft_freeall(const char *list, ...);

#endif
