/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:17:51 by juspende          #+#    #+#             */
/*   Updated: 2019/04/03 20:28:43 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H

# define FT_SSL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line.h"
#include "../libft/includes/libft.h"
#include "../free_all/include/ft_freeall.h"

#ifndef EXIT_HELP
# define EXIT_HELP 42
# endif

#ifndef TRUE
# define TRUE 1
#endif

typedef struct		s_ssl
{
	int		input;
	int		output;
}					t_ssl;

typedef struct		s_ssl_flag
{
	int		p;
	int		q;
	int		r;
	int		s;
	int		h;
	int		v;
	int		i;
}					t_ssl_flag;

int		main(int argc, char **argv);

#endif
