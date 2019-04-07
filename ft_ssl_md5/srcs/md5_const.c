/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_const.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:41:08 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 11:00:09 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_md5.h"
# include "../includes/ft_ssl.h"

void		initialize_md5(t_md5 *md5_c)
{
	md5_c->h[0] = 0x67452301;
	md5_c->h[1] = 0xefcdab89;
	md5_c->h[2] = 0x98badcfe;
	md5_c->h[3] = 0x10325476;
	md5_c->v[0] = md5_c->h[0];
	md5_c->v[1] = md5_c->h[1];
	md5_c->v[2] = md5_c->h[2];
	md5_c->v[3] = md5_c->h[3];
}

uint32_t	to_int32(const uint8_t *bytes)
{
	return (uint32_t) bytes[0]
		| ((uint32_t) bytes[1] << 8)
		| ((uint32_t) bytes[2] << 16)
		| ((uint32_t) bytes[3] << 24);
}

void		to_bytes(uint32_t val, uint8_t *bytes)
{
	bytes[0] = (uint8_t) val;
	bytes[1] = (uint8_t) (val >> 8);
	bytes[2] = (uint8_t) (val >> 16);
	bytes[3] = (uint8_t) (val >> 24);
}

void		ft_md5(uint8_t *initial, size_t len, uint8_t *digest)
{
	t_md5		md5_c;
	uint8_t		*msg;
	size_t		new_len;
	size_t		offset;

	msg = NULL;
	new_len = len + 1;
	while (new_len % (512/8) != 448/8)
		++new_len;
	msg = (uint8_t*)malloc(new_len + 8);
	ft_memcpy(msg, initial, len);
	msg[len] = 0x80;
	offset = len + 1;
	while (offset++ < new_len)
		msg[offset] = 0;
	to_bytes(len * 8, msg + new_len);
	to_bytes(len >> 29, msg + new_len + 4);
	ft_md5Update(new_len, msg, digest, &md5_c);
}
