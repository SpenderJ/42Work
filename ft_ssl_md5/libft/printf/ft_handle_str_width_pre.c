/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str_width_pre.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:23:39 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 18:23:41 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_write_char_with_flags(char *buff, t_arg *param)
{
	if ((param->specifier == '%' || param->specifier == 'c'
				|| param->spec == wrong) && param->minus == TRU)
		*buff++ = param->specifier == '%' ? '%' : param->type.my_char;
	if (param->is_width == TRU
			&& param->null == TRU && param->minus != TRU
			&& param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, '0');
	else if (param->is_width == TRU && param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, ' ');
	if ((param->specifier == '%' || param->specifier == 'c'
				|| param->spec == wrong) && param->minus != TRU)
		*buff++ = param->specifier == '%' ? '%' : param->type.my_char;
	return (buff);
}

char	*ft_write_str_with_flags(char *buff, t_arg *param, int ln_str)
{
	if (param->minus == TRU)
		buff = ft_memcpy(buff, param->type.my_ptrchar, ln_str);
	if (param->is_width == TRU
			&& param->null == TRU && param->minus != TRU
			&& param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, '0');
	else if (param->is_width == TRU && param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, ' ');
	if (param->minus != TRU)
		buff = ft_memcpy(buff, param->type.my_ptrchar, ln_str);
	return (buff);
}

char	*ft_write_unicode_with_flags(char *buff, t_arg *param)
{
	if (param->null == TRU && param->minus != TRU
			&& param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, '0');
	else if (param->is_width && param->width > param->ln_block)
		buff = ft_bzerocustom(buff, param->width - param->ln_block, ' ');
	return (buff);
}
