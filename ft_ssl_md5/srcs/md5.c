/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:40:13 by juspende          #+#    #+#             */
/*   Updated: 2019/04/06 17:35:43 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

const uint32_t k[64] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee ,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501 ,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be ,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821 ,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa ,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8 ,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed ,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a ,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c ,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70 ,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05 ,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665 ,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039 ,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1 ,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1 ,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391 };

const uint32_t r[] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
	5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20, 5,  9, 14, 20,
	4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
	6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

static uint32_t	to_int32(const uint8_t *bytes)
{
	return (uint32_t) bytes[0]
		| ((uint32_t) bytes[1] << 8)
		| ((uint32_t) bytes[2] << 16)
		| ((uint32_t) bytes[3] << 24);
}

static void	to_bytes(uint32_t val, uint8_t *bytes)
{
	bytes[0] = (uint8_t) val;
    bytes[1] = (uint8_t) (val >> 8);
    bytes[2] = (uint8_t) (val >> 16);
    bytes[3] = (uint8_t) (val >> 24);
}

static void	ft_md5op(t_md5 *md5_c)
{
	md5_c->v[4] = -1;
	while (++md5_c->v[4] < 64)
	{
		if (md5_c->v[4] < 16 && (md5_c->v[6] = md5_c->v[4]) == md5_c->v[6])
			md5_c->v[5] = (md5_c->v[1] & md5_c->v[2]) | ((~md5_c->v[1]) &
					md5_c->v[3]);
		else if (md5_c->v[4] < 32 && (md5_c->v[6] = (5 * md5_c->v[4] + 1) % 16)
				== md5_c->v[6])
			md5_c->v[5] = (md5_c->v[3] & md5_c->v[1]) | ((~md5_c->v[3]) &
					md5_c->v[2]);
		else if (md5_c->v[4] < 48 && (md5_c->v[6] = (3 * md5_c->v[4] + 5) % 16)
				== md5_c->v[6])
			md5_c->v[5] = md5_c->v[1] ^ md5_c->v[2] ^ md5_c->v[3];
		else if ((md5_c->v[6] = (7 * md5_c->v[4]) % 16) == md5_c->v[6])
			md5_c->v[5] = md5_c->v[2] ^ (md5_c->v[1] | (~md5_c->v[3]));
		md5_c->v[7] = md5_c->v[3];
		md5_c->v[3] = md5_c->v[2];
		md5_c->v[2] = md5_c->v[1];
		md5_c->v[1] = md5_c->v[1] + LEFTROTATE((md5_c->v[0] + md5_c->v[5] +
					k[md5_c->v[4]] + md5_c->w[md5_c->v[6]]), r[md5_c->v[4]]);
		md5_c->v[0] = md5_c->v[7];
	}
}

static void	initialize_md5(t_md5 *md5_c)
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

static void	ft_md5Update(size_t new_len, uint8_t *msg, uint8_t *digest, t_md5 *md5_c)
{
	size_t		offset;

	initialize_md5(md5_c);
	offset = 0;
	while (offset < new_len)
	{
		md5_c->v[4] = -1;
		while (++md5_c->v[4] < 16)
			md5_c->w[md5_c->v[4]] = to_int32(msg + offset + md5_c->v[4]*4);
		ft_md5op(md5_c);
		offset += (512/8);
		md5_c->h[0] += md5_c->v[0];
		md5_c->h[1] += md5_c->v[1];
		md5_c->h[2] += md5_c->v[2];
		md5_c->h[3] += md5_c->v[3];
	}
	free(msg);
	to_bytes(md5_c->h[0], digest);
	to_bytes(md5_c->h[1], digest + 4);
	to_bytes(md5_c->h[2], digest + 8);
	to_bytes(md5_c->h[3], digest + 12);
}

static void	ft_md5(uint8_t *initial, size_t len, uint8_t *digest)
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

void		md5(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	int				index;
	uint8_t			hash[16];
	int				z;
	size_t			len;

	index = 0;
	z = -1;
	(void)ssl_flag;
	len = ft_strlen(ssl->to_hash[index]);
	while (++z < MD5_ROTA)
	{
		ft_md5((uint8_t*)ssl->to_hash[index], len, hash);
	}
	z = -1;
	while (++z < 16)
		printf("%2.2x", hash[z]);
	puts("");
	return ;
}