/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:40:13 by juspende          #+#    #+#             */
/*   Updated: 2019/04/05 19:33:59 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static void	ft_reverseByte(unsigned char *buf, unsigned longs)
{
	unsigned long	t;

	while (--longs)
	{
		t = (unsigned long) ((unsigned) buf[3] << 8 | buf[2]) << 16 |
				((unsigned) buf[1] << 8 | buf[0]);
		*(unsigned long *) buf = t;
		buf = buf + 4;
	}
}

static void	ft_md5Init(t_md5 *md5_struct)
{
	md5_struct->buf[0] = 0x67452301;
	md5_struct->buf[1] = 0xefcdab89;
	md5_struct->buf[2] = 0x98badcfe;
	md5_struct->buf[3] = 0x10325476;
	
	md5_struct->bits[0] = 0;
	md5_struct->bits[1] = 0;
	return ;
}

static void	ft_md5Update(t_md5 *md5_struct, char *to_hash, unsigned long len)
{
	unsigned long	t;

	t = md5_struct->bits[0];
	if ((md5_struct->bits[0] = t + ((unsigned long) len << 3)) < t)
		++md5_struct->bits[1];
	md5_struct->bits[1] =  md5_struct->bits[1] + (len >> 29);
	t = (t >> 3) & 0x3f;
	if (t)
	{
		unsigned char *p = (unsigned char *) md5_struct->in + t;
		t = 64 - t;
		if (len < t)
		{
			ft_memcpy(p, to_hash, len);
			return ;
		}
		ft_memcpy(p, to_hash, t);
		ft_reverseByte(md5_struct->in, 16);
		ft_md5Transform(md5_struct->buf, (unsigned long *) md5_struct->in);
		to_hash += t;
		len -= t;
	}
	while (len >= 64)
	{
		ft_memcpy (md5_struct->in, to_hash, 64);
		ft_reverseByte(md5_struct->in, 16);
		ft_md5Transform(md5_struct->buf, (unsigned long *) md5_struct->in);
		to_hash += 64;
		len -= 64;
	}
	ft_memcpy(md5_struct->in, to_hash, len);
}

static void	ft_md5Final(unsigned char hash[16], t_md5 *md5_struct)
{
	(void)hash;
	(void)md5_struct;
	return ;
}

void		md5(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	int				index;
	t_md5			md5_struct;
	unsigned char	hash[16];

	index = -1;
	(void)ssl_flag;
	while (++index < ssl->size_printed)
	{
		ft_md5Init(&md5_struct);
		ft_md5Update(&md5_struct, ssl->to_hash[index],
				(unsigned long)ft_strlen(ssl->to_hash[index]));
		printf("%u\n%u\n%u\n%u\n", md5_struct.in[0], md5_struct.in[1], md5_struct.in[2], md5_struct.in[3]);
		ft_md5Final(hash, &md5_struct);
	}
	return ;
}
