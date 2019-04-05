/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:11:10 by juspende          #+#    #+#             */
/*   Updated: 2019/04/05 15:08:20 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/ft_md5.h"

static void	ft_md5f2(unsigned int val[4], unsigned int const in[16])
{
	MD5STEP (F2, val[0], val[1], val[2], val[3], in[1] + 0xf61e2562, 5);
	MD5STEP (F2, val[3], val[0], val[1], val[2], in[6] + 0xc040b340, 9);
	MD5STEP (F2, val[2], val[3], val[0], val[1], in[11] + 0x265e5a51, 14);
	MD5STEP (F2, val[1], val[2], val[3], val[0], in[0] + 0xe9b6c7aa, 20);
	MD5STEP (F2, val[0], val[1], val[2], val[3], in[5] + 0xd62f105d, 5);
	MD5STEP (F2, val[3], val[0], val[1], val[2], in[10] + 0x02441453, 9);
	MD5STEP (F2, val[2], val[3], val[0], val[1], in[15] + 0xd8a1e681, 14);
	MD5STEP (F2, val[1], val[2], val[3], val[0], in[4] + 0xe7d3fbc8, 20);
	MD5STEP (F2, val[0], val[1], val[2], val[3], in[9] + 0x21e1cde6, 5);
	MD5STEP (F2, val[3], val[0], val[1], val[2], in[14] + 0xc33707d6, 9);
	MD5STEP (F2, val[2], val[3], val[0], val[1], in[3] + 0xf4d50d87, 14);
	MD5STEP (F2, val[1], val[2], val[3], val[0], in[8] + 0x455a14ed, 20);
	MD5STEP (F2, val[0], val[1], val[2], val[3], in[13] + 0xa9e3e905, 5);
	MD5STEP (F2, val[3], val[0], val[1], val[2], in[2] + 0xfcefa3f8, 9);
	MD5STEP (F2, val[2], val[3], val[0], val[1], in[7] + 0x676f02d9, 14);
	MD5STEP (F2, val[1], val[2], val[3], val[0], in[12] + 0x8d2a4c8a, 20);
}

static void	ft_md5f1(unsigned int val[4], unsigned int const in[16])
{
	MD5STEP (F1, val[0], val[1], val[2], val[3], in[0] + 0xd76aa478, 7);
	MD5STEP (F1, val[3], val[0], val[1], val[2], in[1] + 0xe8c7b756, 12);
	MD5STEP (F1, val[2], val[3], val[0], val[1], in[2] + 0x242070db, 17);
	MD5STEP (F1, val[1], val[2], val[3], val[0], in[3] + 0xc1bdceee, 22);
	MD5STEP (F1, val[0], val[1], val[2], val[3], in[4] + 0xf57c0faf, 7);
	MD5STEP (F1, val[3], val[0], val[1], val[2], in[5] + 0x4787c62a, 12);
	MD5STEP (F1, val[2], val[3], val[0], val[1], in[6] + 0xa8304613, 17);
	MD5STEP (F1, val[1], val[2], val[3], val[0], in[7] + 0xfd469501, 22);
	MD5STEP (F1, val[0], val[1], val[2], val[3], in[8] + 0x698098d8, 7);
	MD5STEP (F1, val[3], val[0], val[1], val[2], in[9] + 0x8b44f7af, 12);
	MD5STEP (F1, val[2], val[3], val[0], val[1], in[10] + 0xffff5bb1, 17);
	MD5STEP (F1, val[1], val[2], val[3], val[0], in[11] + 0x895cd7be, 22);
	MD5STEP (F1, val[0], val[1], val[2], val[3], in[12] + 0x6b901122, 7);
	MD5STEP (F1, val[3], val[0], val[1], val[2], in[13] + 0xfd987193, 12);
	MD5STEP (F1, val[2], val[3], val[0], val[1], in[14] + 0xa679438e, 17);
	MD5STEP (F1, val[1], val[2], val[3], val[0], in[15] + 0x49b40821, 22);
}

void		ft_md5Transform(unsigned int buf[4], unsigned int const in[16])
{
	unsigned int	val[4];

	val[0] = buf[0];
	val[1] = buf[1];
	val[2] = buf[2];
	val[3] = buf[3];

	ft_md5f1(val, in);
//	ft_md5f2(val, in);
//	ft_md5f3(val, in);
//	ft_md5f4(val, in);
}
