/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:40:13 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 10:51:08 by juspende         ###   ########.fr       */
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

void		ft_md5Update(size_t new_len, uint8_t *msg, uint8_t *digest,
		t_md5 *md5_c)
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

void		md5(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	int				index;
	uint8_t			hash[16];
	int				z;
	size_t			len;

	index = -1;
	(void)ssl_flag;
	while (++index < ssl->size_printed)
	{
		z = -1;
		len = ft_strlen(ssl->to_hash[index]);
		while (++z < MD5_ROTA && ssl->to_hash[index])
			ft_md5((uint8_t*)ssl->to_hash[index], len, hash);
		z = -1;
		if (ssl->c_stdin && ssl->to_hash[index] && index == 0)
			while (++z < 16)
				printf("%2.2x", hash[z]);
		else if (ssl->to_hash[index])
		{
			ft_printf("MD5 (%s) = ", ssl->filenames[index - ssl->c_stdin]);
			while (++z < 16)
				printf("%2.2x", hash[z]);
		}
		else
			printf("ft_ssl: md5: %s: No such file or directory", ssl->filenames[index +
					ssl->c_stdin]);
		printf("\n");
	}
	return ;
}
