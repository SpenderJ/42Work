/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:38:32 by juspende          #+#    #+#             */
/*   Updated: 2019/04/06 17:30:39 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MD5_H

# define FT_MD5_H

# include <string.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_ssl.h"

# define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
# define MD5_ROTA 1000000

typedef struct		s_md5
{
	uint32_t	h[4];
	uint32_t	w[16];
	uint32_t	v[9];
}					t_md5;

#endif
