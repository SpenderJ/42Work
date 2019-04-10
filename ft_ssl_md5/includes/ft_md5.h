/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_md5.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:38:32 by juspende          #+#    #+#             */
/*   Updated: 2019/04/10 15:35:11 by juspende         ###   ########.fr       */
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

void		initialize_md5(t_md5 *md5_c);
uint32_t	to_int32(const uint8_t *bytes);
void		to_bytes(uint32_t val, uint8_t *bytes);
void		ft_md5(uint8_t *initial, size_t len, uint8_t *digest);
void		ft_md5Update(size_t new_len, uint8_t *msg, uint8_t *digest,
		t_md5 *md5_c);

#endif
