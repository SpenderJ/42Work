/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:20:22 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 17:20:25 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_write_dec_with_minus(char *buff, t_arg *param, char *nbr, int neg)
{
	if (param->plus == TRU || neg == TRU)
		buff = ft_write_dec_plus(buff, neg);
	else if (param->space == TRU)
		buff = ft_write_dec_space(buff);
	else if (((param->specifier == 'x' || param->specifier == 'X')
			&& param->sharp == TRU && param->type.my_uint != 0)
			|| param->specifier == 'p')
		buff = param->specifier == 'X'
				? ft_memcpy(buff, "0X", 2) : ft_memcpy(buff, "0x", 2);
	else if ((param->specifier == 'o' || param->specifier == 'O')
			&& param->sharp == TRU
			&& param->type.my_uint != 0)
		buff = ft_memcpy(buff, "0", 1);
	if (param->is_pre == TRU)
		if ((size_t)param->precision > ft_strlen(nbr))
			buff = ft_bzerocustom(buff, param->precision - ft_strlen(nbr), '0');
	buff = ft_memcpy(buff, nbr, ft_strlen(nbr));
	if (param->is_width == TRU)
		if (param->width > param->ln_block)
			buff = ft_bzerocustom(buff, param->width - param->ln_block, ' ');
	return (buff);
}

char	*ft_write_dec_with_flags(char *buff, t_arg *param, char *nbr, int neg)
{
	if (param->minus == TRU)
		buff = ft_write_dec_with_minus(buff, param, nbr, neg);
	else
	{
		if (param->is_width == TRU && param->is_pre == TRU)
			buff = ft_width_and_pre(buff, param, nbr, neg);
		else if (param->is_width == TRU && param->is_pre != TRU)
			buff = ft_only_width(buff, param, nbr, neg);
		else if (param->is_width != TRU && param->is_pre == TRU)
			buff = ft_only_pre(buff, param, nbr, neg);
		else
			buff = ft_no_pre_no_width(buff, param, nbr, neg);
	}
	return (buff);
}

char	*ft_decimal_else(char *buff, t_arg *param, int is_neg)
{
	char	*nbr;

	nbr = ft_uitoa(param->type.my_uint);
	buff = ft_write_dec_with_flags(buff, param, nbr, is_neg);
	free(nbr);
	return (buff);
}

char	*ft_decimal(char *buff, t_arg *param)
{
	char	*nbr;
	int		is_neg;

	is_neg = FAL;
	if (param->type.my_int == (intmax_t) - 9223372036854775808ULL)
	{
		nbr = "9223372036854775808\0";
		is_neg = TRU;
		buff = ft_write_dec_with_flags(buff, param, nbr, is_neg);
	}
	else if (param->specifier == 'd' || param->specifier == 'i'
			|| param->specifier == 'D')
	{
		is_neg = param->type.my_int < 0 ? TRU : FAL;
		nbr = ft_itoa(ft_abs(param->type.my_int));
		buff = ft_write_dec_with_flags(buff, param, nbr, is_neg);
		free(nbr);
		return (buff);
	}
	else
		buff = ft_decimal_else(buff, param, is_neg);
	return (buff);
}

char	*ft_convert_decimal(char *buff, t_arg *param)
{
	char *nbr;

	if (param->specifier == 'x' || param->specifier == 'p')
		nbr = ft_itoa_base(param->type.my_uint, 16, "0123456789abcdef");
	else if (param->specifier == 'X')
		nbr = ft_itoa_base(param->type.my_uint, 16, "0123456789ABCDEF");
	else
		nbr = ft_itoa_base(param->type.my_uint, 8, "01234567");
	if (param->is_pre == TRU
			&& (param->specifier == 'x' || param->specifier == 'X')
			&& param->type.my_uint == 0)
		*nbr = '\0';
	buff = ft_write_dec_with_flags(buff, param, nbr, FAL);
	free(nbr);
	return (buff);
}
