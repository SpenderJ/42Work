/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:41:11 by juspende          #+#    #+#             */
/*   Updated: 2019/04/16 10:07:05 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha256.h"

static int		append_pad_bits_sha256(uint32_t *buf, uint32_t fsize)
{
	size_t		size;
	uint32_t	z;
	size_t		n;
	int			i;

	i = -1;
	z = CHAR_BIT * fsize;
	size = z + 64;
	while (++size % 512)
		;
	n = size / 512;
	size % 512 ? n++ : 1;
	((char*)buf)[fsize] = 0x80;
	while (++i < (int)(n * 16) - 1)
		buf[i] = swap_int32(buf[i]);
	buf[((n * 512 - 64) / 32) + 1] = z;
	return (n * 64);
}

static void			sha256_r_algo(uint32_t *buff, uint32_t *tmp_words)
{
	uint64_t	i[7];

	i[0] = -1;
	while (++(i[0]) < 64)
	{
		i[1] = EP1(buff[E]);
		i[3] = CH(buff[E], buff[F], buff[G]);
		i[4] = buff[H] + i[1] + i[3] + g_k[i[0]] + tmp_words[i[0]];
		i[2] = EP0(buff[A]);
		i[5] = MAJ(buff[A], buff[B], buff[C]);
		i[6] = i[2] + i[5];
		buff[H] = buff[G];
		buff[G] = buff[F];
		buff[F] = buff[E];
		buff[E] = buff[D] + i[4];
		buff[D] = buff[C];
		buff[C] = buff[B];
		buff[B] = buff[A];
		buff[A] = i[4] + i[6];
	}
}

static void			exec_sha256_cycle(t_sha256 *sha256, uint32_t *word)
{
	int				chunk_num;
	uint32_t		buffer[8];
	static uint32_t	tmp_words[64];
	int				i;
	int				j;

	i = -1;
	chunk_num = sha256->len_bytes / 64;
	ft_bzero(tmp_words, 64 * sizeof(uint32_t));
	while (++i < chunk_num && (j = -1))
	{
		ft_memcpy(buffer, sha256->buffer, sizeof(buffer));
		init_tmp_words(tmp_words, (word + i * 16));
		sha256_r_algo(buffer, tmp_words);
		while (++j < 8)
			sha256->buffer[j] += buffer[j];
	}
}

static uint32_t	*sha256_word(const char *word, t_sha256 *sha256, uint32_t size)
{
	uint8_t		*message;
	uint32_t	*digest;

	message = ft_memalloc(sha256->len_bytes);
	ft_bzero(message, sha256->len_bytes);
	ft_memcpy(message, word, size);
	sha256->len_bytes = append_pad_bits_sha256((uint32_t *)message, size);
	sha256->len_bits = sha256->len_bytes * CHAR_BIT;
	exec_sha256_cycle(sha256, (uint32_t *)message);
	free(message);
	digest = ft_memalloc(sizeof(sha256->buffer));
	ft_memcpy(digest, sha256->buffer, sizeof(sha256->buffer));
	return (digest);
}

void			sha256(t_ssl *ssl, t_ssl_flag *ssl_flag)
{
	t_sha256	sha256;
	uint32_t	*res;
	int			index;

	index = -1;
	res = NULL;
	while (++index < ssl->size_printed)
	{
		ft_bzero((void *)&sha256, sizeof(t_sha256 *));
		sha256.buffer[A] = 0x6a09e667;
		sha256.buffer[B] = 0xbb67ae85;
		sha256.buffer[C] = 0x3c6ef372;
		sha256.buffer[D] = 0xa54ff53a;
		sha256.buffer[E] = 0x510e527f;
		sha256.buffer[F] = 0x9b05688c;
		sha256.buffer[G] = 0x1f83d9ab;
		sha256.buffer[H] = 0x5be0cd19;
		sha256.len_bytes = bytenum((size_t)(ssl->f_size + 9));
		if (ssl->to_hash[index] != NULL)
			res = sha256_word(ssl->to_hash[index], &sha256, ssl->f_size[index]);
		output(res, ssl, ssl_flag, index);
	}
	return ;
}
