/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:15:00 by juspende          #+#    #+#             */
/*   Updated: 2019/04/15 14:22:50 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_sha256.h"

inline uint32_t	swap_int32(const uint32_t value)
{
	uint32_t result;

	result = 0;
	result |= (value & 0x000000FF) << 24;
	result |= (value & 0x0000FF00) << 8;
	result |= (value & 0x00FF0000) >> 8;
	result |= (value & 0xFF000000) >> 24;
	return (result);
}

inline size_t	bytenum(size_t len)
{
	while (len * CHAR_BIT % 64)
		++len;
	return (len);
}

inline void			init_tmp_words(uint32_t *w, uint32_t *block)
{
	uint64_t	i;
	uint32_t	tmp_1;
	uint32_t	tmp_2;

	ft_memcpy(w, block, 16 * sizeof(uint32_t));
	i = 15;
	while (++i < 64)
	{
		tmp_1 = SIG0(w[i - 15]);
		tmp_2 = SIG1(w[i - 2]);
		w[i] = w[i - 16] + tmp_1 + w[i - 7] + tmp_2;
	}
}
