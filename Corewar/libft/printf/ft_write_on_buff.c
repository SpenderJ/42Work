/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_on_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:20:36 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 17:20:39 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*ft_write_convertion(t_arg *param, char *buff)
{
	char	specifier;

	specifier = param->specifier;
	if (specifier == 'd' || specifier == 'i' || specifier == 'u'
			|| specifier == 'D' || specifier == 'U')
		buff = ft_decimal(buff, param);
	else if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		buff = ft_convert_decimal(buff, param);
	else if (specifier == 'o' || specifier == 'O')
		buff = ft_convert_decimal(buff, param);
	else if (specifier == 's' || specifier == 'c' || specifier == '%'
			|| param->spec == wrong)
		buff = ft_string(buff, param);
	else if (specifier == 'C' || specifier == 'S')
		buff = ft_unicode(buff, param);
	else if (specifier == 'b')
		buff = ft_memcpy(buff, ft_itoa_base(param->type.my_int, 2, "01"),
				ft_base_digitlen(param->type.my_int, 2));
	return (buff);
}

int		ft_write_on_buff(const char *format, char *buff, t_arg *param)
{
	int		ln_format;
	char	next_to;

	while (*format)
	{
		next_to = param == NULL ? '\0' : '%';
		if ((ln_format = ft_strchr(format, next_to) - format) < 0)
			return (-1);
		ft_memcpy(buff, format, ln_format);
		format += ln_format;
		buff += ln_format;
		if (*format == '%')
		{
			buff = ft_write_convertion(param, buff);
			if (param->spec == percent)
				format = ft_strchr(format + 1, param->specifier) + 1;
			else
				format = ft_strchr(format, param->specifier) + 1;
			param = param->next;
		}
	}
	return (0);
}
