/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_letters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:20:13 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 17:20:16 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_cpy_str(t_arg *param)
{
	int		ln_str;

	if (param->is_pre == TRU
				&& ft_strlen(param->type.my_ptrchar) > (size_t)param->precision)
		ln_str = param->precision;
	else
		ln_str = ft_strlen(param->type.my_ptrchar);
	return (ln_str);
}

char	*ft_string(char *buff, t_arg *param)
{
	int		ln_str;

	if (param->len == l && param->specifier != '%')
		return (ft_unicode(buff, param));
	if (param->specifier == 's')
	{
		ln_str = ft_cpy_str(param);
		buff = ft_write_str_with_flags(buff, param, ln_str);
	}
	else
		buff = ft_write_char_with_flags(buff, param);
	return (buff);
}

char	*ft_unicode(char *buff, t_arg *param)
{
	int	i;

	i = 0;
	if (param->minus != TRU)
		buff = ft_write_unicode_with_flags(buff, param);
	if (param->specifier == 'S' || param->specifier == 's')
	{
		while (i < param->nbr_utf8_char)
		{
			buff = ft_utf8(param->type.my_wchar_t[i], buff);
			++i;
		}
	}
	else
		buff = ft_utf8(param->type.my_wint_t, buff);
	if (param->minus == TRU)
		buff = ft_write_unicode_with_flags(buff, param);
	return (buff);
}
