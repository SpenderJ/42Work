/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:40:13 by juspende          #+#    #+#             */
/*   Updated: 2019/04/14 15:58:50 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_md5.h"

static int		append_pad_bits_md5(uint8_t *buf, uint32_t osize)
{
	size_t		size;
	uint32_t	inp_bitlen;

	size = osize * CHAR_BIT;
	while (++size % 512 != 448)
		;
	size /= CHAR_BIT;
	buf[osize] = 0x80;
	inp_bitlen = osize * CHAR_BIT;
	ft_memcpy(buf + size, &inp_bitlen, 4);
	return (size + 8);
}

static void		md5_r_algo(uint32_t *bufs, uint32_t *chunk)
{
	int			i;
	uint32_t	f;
	uint32_t	g;
	uint32_t	tmp;
	uint32_t	tmpf;

	i = -1;
	while (++i < 64)
	{
		if (i < 16 && (f = F(bufs[B], bufs[C], bufs[D])))
			g = i;
		else if (i < 32 && (f = G(bufs[B], bufs[C], bufs[D])))
			g = (i * 5 + 1) % 16;
		else if (i < 48 && (f = H(bufs[B], bufs[C], bufs[D])))
			g = (i * 3 + 5) % 16;
		else if (i < 64 && (f = I(bufs[B], bufs[C], bufs[D])))
			g = (i * 7) % 16;
		tmpf = f;
		f += bufs[A] + g_k[i] + chunk[g];
		tmp = bufs[A];
		bufs[A] = bufs[D];
		bufs[D] = bufs[C];
		bufs[C] = bufs[B];
		bufs[B] += LEFTROTATE(f, g_r[i]);
	}
}

static void		exec_md5_cycle(t_md5 *md5, uint8_t *word)
{
	int			chunk_num;
	uint32_t	buffer[4];
	int			i;
	int			j;

	i = -1;
	chunk_num = md5->len_bits / 512;
	while (++i < chunk_num && (j = -1))
	{
		ft_memcpy(buffer, md5->buffer, sizeof(buffer));
		md5_r_algo(buffer, (uint32_t*)(word + i * 64));
		while (++j < 4)
			md5->buffer[j] += buffer[j];
	}
}

static uint32_t	*md5_word(const char *word, t_md5 *md5, uint32_t size)
{
	uint8_t			*message;
	uint32_t		*digest;

	message = ft_memalloc((size + 64) * sizeof(char));
	ft_memcpy(message, word, size);
	md5->len_bytes = append_pad_bits_md5(message, size);
	md5->len_bits = md5->len_bytes * CHAR_BIT;
	exec_md5_cycle(md5, message);
	free(message);
	digest = ft_memalloc(sizeof(md5->buffer) / 2);
	ft_memcpy(digest, md5->buffer, sizeof(md5->buffer) / 2);
	return (digest);
}

void			md5(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	t_md5		md5;
	uint32_t	*res;
	int			index;

	index = -1;
	res = NULL;
	while (++index < ssl->size_printed)
	{
		ft_bzero((void *)&md5, sizeof(t_md5 *));
		md5.buffer[A] = 0x67452301;
		md5.buffer[B] = 0xefcdab89;
		md5.buffer[C] = 0x98badcfe;
		md5.buffer[D] = 0x10325476;
		if (ssl->to_hash[index] != NULL)
			res = md5_word(ssl->to_hash[index], &md5, ssl->f_size[index]);
		output(res, ssl, ssl_flag, index);
	}
	return ;
}
