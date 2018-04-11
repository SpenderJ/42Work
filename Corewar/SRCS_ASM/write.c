/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:25:30 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/05 14:25:41 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			ft_write(t_asm *strukt, const void *tmp, size_t len)
{
	int			i;
	const char	*tmp0;
	char		*tmp1;
	int			fd;

	fd = strukt->fd_cor;
	i = 0;
	tmp0 = tmp;
	tmp1 = NULL;
	write(fd, tmp, len);
	if (strukt->a == 0 || strukt->a == 2)
		return ;
	while (i < len)
	{
		ft_put(ft_itoa_base(tmp0[i], 16), ' ', 1, 1);
		i++;
	}
}

void			ft_write_ui(unsigned int value, t_asm *strukt)
{
	unsigned int tmp;

	tmp = value >> 24;
	ft_write(strukt, &tmp, 1);
	tmp = value >> 16;
	ft_write(strukt, &tmp, 1);
	tmp = value >> 8;
	ft_write(strukt, &tmp, 1);
	tmp = value;
	ft_write(strukt, &tmp, 1);
}

void			ft_write_us(unsigned short value, t_asm *strukt)
{
	unsigned short tmp;

	tmp = value >> 8;
	ft_write(strukt, &tmp, 1);
	tmp = value;
	ft_write(strukt, &tmp, 1);
}

unsigned char	ft_write_codage_ext(char *s, t_asm *st, size_t codage, int i)
{
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == DIRECT_CHAR)
		codage = codage | 0b00100000;
	else if (s[i] == 'r')
		codage = codage | 0b00010000;
	else
		codage = codage | 0b00110000;
	while (s[i] && s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR)
		i++;
	if (s[i] == 0 || s[i] == ' ' || s[i] == '\t' || s[i] == COMMENT_CHAR)
		return (codage);
	i++;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == DIRECT_CHAR)
		codage = codage | 0b00001000;
	else if (s[i] == 'r')
		codage = codage | 0b00000100;
	else
		codage = codage | 0b00001100;
	return (codage);
}

unsigned char	ft_write_codage(char *s, t_asm *strukt)
{
	unsigned char	codage;
	int				i;

	i = 0;
	codage = 0;
	if (s[i] == DIRECT_CHAR)
		codage = codage | 0b10000000;
	else if (s[i] == 'r')
		codage = codage | 0b01000000;
	else
		codage = codage | 0b11000000;
	while (s[i] && s[i] != SEPARATOR_CHAR && s[i] != COMMENT_CHAR)
		i++;
	if (s[i] == 0 || s[i] == ' ' || s[i] == '\t' || s[i] == COMMENT_CHAR)
		return (codage);
	i++;
	return (ft_write_codage_ext(s, strukt, codage, i));
}
