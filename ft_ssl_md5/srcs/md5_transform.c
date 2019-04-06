/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:11:10 by juspende          #+#    #+#             */
/*   Updated: 2019/04/05 19:33:00 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/ft_md5.h"

static unsigned long	*ft_md5f4(unsigned long val[4], unsigned long const in[16])
{
	MD5STEP (F4, val[0], val[1], val[2], val[3], in[0] + 0xf4292244, 6);
	MD5STEP (F4, val[3], val[0], val[1], val[2], in[7] + 0x432aff97, 10);
	MD5STEP (F4, val[2], val[3], val[0], val[1], in[14] + 0xab9423a7, 15);
	MD5STEP (F4, val[1], val[2], val[3], val[0], in[5] + 0xfc93a039, 21);
	MD5STEP (F4, val[0], val[1], val[2], val[3], in[12] + 0x655b59c3, 6);
	MD5STEP (F4, val[3], val[0], val[1], val[2], in[3] + 0x8f0ccc92, 10);
	MD5STEP (F4, val[2], val[3], val[0], val[1], in[10] + 0xffeff47d, 15);
	MD5STEP (F4, val[1], val[2], val[3], val[0], in[1] + 0x85845dd1, 21);
	MD5STEP (F4, val[0], val[1], val[2], val[3], in[8] + 0x6fa87e4f, 6);
	MD5STEP (F4, val[3], val[0], val[1], val[2], in[15] + 0xfe2ce6e0, 10);
	MD5STEP (F4, val[2], val[3], val[0], val[1], in[6] + 0xa3014314, 15);
	MD5STEP (F4, val[1], val[2], val[3], val[0], in[13] + 0x4e0811a1, 21);
	MD5STEP (F4, val[0], val[1], val[2], val[3], in[4] + 0xf7537e82, 6);
	MD5STEP (F4, val[3], val[0], val[1], val[2], in[11] + 0xbd3af235, 10);
	MD5STEP (F4, val[2], val[3], val[0], val[1], in[2] + 0x2ad7d2bb, 15);
	MD5STEP (F4, val[1], val[2], val[3], val[0], in[9] + 0xeb86d391, 21);
	return (val);
}

static unsigned long	*ft_md5f3(unsigned long val[4], unsigned long const in[16])
{
	MD5STEP (F3, val[0], val[1], val[2], val[3], in[5] + 0xfffa3942, 4);
	MD5STEP (F3, val[3], val[0], val[1], val[2], in[8] + 0x8771f681, 11);
	MD5STEP (F3, val[2], val[3], val[0], val[1], in[11] + 0x6d9d6122, 16);
	MD5STEP (F3, val[1], val[2], val[3], val[0], in[14] + 0xfde5380c, 23);
	MD5STEP (F3, val[0], val[1], val[2], val[3], in[1] + 0xa4beea44, 4);
	MD5STEP (F3, val[3], val[0], val[1], val[2], in[4] + 0x4bdecfa9, 11);
	MD5STEP (F3, val[2], val[3], val[0], val[1], in[7] + 0xf6bb4b60, 16);
	MD5STEP (F3, val[1], val[2], val[3], val[0], in[10] + 0xbebfbc70, 23);
	MD5STEP (F3, val[0], val[1], val[2], val[3], in[13] + 0x289b7ec6, 4);
	MD5STEP (F3, val[3], val[0], val[1], val[2], in[0] + 0xeaa127fa, 11);
	MD5STEP (F3, val[2], val[3], val[0], val[1], in[3] + 0xd4ef3085, 16);
	MD5STEP (F3, val[1], val[2], val[3], val[0], in[6] + 0x04881d05, 23);
	MD5STEP (F3, val[0], val[1], val[2], val[3], in[9] + 0xd9d4d039, 4);
	MD5STEP (F3, val[3], val[0], val[1], val[2], in[12] + 0xe6db99e5, 11);
	MD5STEP (F3, val[2], val[3], val[0], val[1], in[15] + 0x1fa27cf8, 16);
	MD5STEP (F3, val[1], val[2], val[3], val[0], in[2] + 0xc4ac5665, 23);
	return (ft_md5f4(val, in));
}

static unsigned long	*ft_md5f2(unsigned long val[4], unsigned long const in[16])
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
	return (ft_md5f3(val, in));
}

static unsigned long	*ft_md5f1(unsigned long val[4], unsigned long const in[16])
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
	return (ft_md5f2(val, in));
}

void		ft_md5Transform(unsigned long buf[4], unsigned long const in[16])
{
	unsigned long	*val;

	if ((val = malloc(sizeof(long) * 5)) == NULL)
		return ;
	val[0] = buf[0];
	val[1] = buf[1];
	val[2] = buf[2];
	val[3] = buf[3];

	val = ft_md5f1(val, in);
	buf[0] += val[0];
	buf[1] += val[1];
	buf[2] += val[2];
	buf[3] += val[3];
}
