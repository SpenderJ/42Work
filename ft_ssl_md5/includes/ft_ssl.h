/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:17:51 by juspende          #+#    #+#             */
/*   Updated: 2019/04/04 15:42:55 by juspende         ###   ########.fr       */
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

#ifndef MAX_FILES
# define MAX_FILES 10
#endif

#ifndef SEG
# define SEG -2
#endif

#ifndef TRUE
# define TRUE 1
#endif

typedef struct		s_ssl
{
	int		c_stdin;
	int		output;
	int		md5;
	int		sha256;
	int		sha512;
	int		whirpool;
	char	**filenames;
	char	**to_hash;
	int		size_printed;
}					t_ssl;

typedef struct		s_ssl_flag
{
	int		p;
	int		q;
	int		r;
	int		s;
	int		h;
	int		v;
}					t_ssl_flag;

int		main(int argc, char **argv);
int		io(t_ssl *ssl);
void	md5(t_ssl *ssl, t_ssl_flag *ssl_flag);
void	sha256(t_ssl *ssl, t_ssl_flag *ssl_flag);
void	sha512(t_ssl *ssl, t_ssl_flag *ssl_flag);
void	whirpool(t_ssl *ssl, t_ssl_flag *ssl_flag);

#endif
