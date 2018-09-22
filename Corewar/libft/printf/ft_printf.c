/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 17:19:20 by jebossue          #+#    #+#             */
/*   Updated: 2017/03/28 17:19:22 by jebossue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_arg	*ft_check_param(const char *format)
{
	char	*next_param;
	t_arg	*param;

	if (*format == '\0' || (next_param = ft_strchr(format, '%')) == NULL
			|| *next_param == '\0' || *(++next_param) == '\0')
		return (NULL);
	if ((param = (t_arg *)malloc(sizeof(*param))) == NULL)
		return (NULL);
	ft_set_param(param);
	while (param->spec == no
			&& (ft_check_flags(&next_param, param)
				|| ft_check_width(&next_param, param)
				|| ft_check_precision(&next_param, param)
				|| ft_check_length(&next_param, param)
				|| ft_find_specifier(&next_param, param)))
		;
	if (*next_param == '\0' && param->specifier == '\0')
	{
		free(param);
		return (NULL);
	}
	else
		param->next = *next_param ? ft_check_param(next_param + 1) : NULL;
	return (param);
}

int		ft_check_full_len(const char *format, va_list *ap, t_arg *param)
{
	int		ln;

	ln = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (param)
			{
				if ((ln = ft_convert_size(ap, param, ln)) == -1)
					return (-1);
				if (param->spec == percent)
					format = ft_strchr(format + 1, param->specifier);
				else
					format = ft_strchr(format, param->specifier);
				param = param->next;
			}
			else
				return (ln);
			--ln;
		}
		++ln;
		++format;
	}
	return (ln);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list ap;
	int		ln;
	char	*buff;
	t_arg	*param;

	param = ft_check_param(format);
	va_start(ap, format);
	if ((ln = ft_check_full_len(format, &ap, param)) == -1)
	{
		va_end(ap);
		ft_free_param(param);
		return (-1);
	}
	va_end(ap);
	if ((buff = (char *)malloc(sizeof(*buff) * (ln + 1))) == NULL)
		return (-1);
	buff[ln] = '\0';
	if (ft_write_on_buff(format, buff, param) == -1)
	{
		ft_free_printf(buff, param);
		return (-1);
	}
	write(1, buff, ln);
	ft_free_printf(buff, param);
	return (ln);
}
