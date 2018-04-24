/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:59:35 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/31 15:27:56 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_is_normal_s(t_params *arg, va_list lst)
{
	int			malloc_size;
	int			width;
	int			n;
	char		*str;

	str = ft_prop_cast_s(arg, lst);
	if (str == NULL && arg->width == 0)
		return (str = ft_strdup("(null)"));
	width = arg->width;
	n = 0;
	malloc_size = ft_prec_s(0, ft_strlen(str), arg);
	malloc_size = ft_malloc_width_s(malloc_size, &n, arg);
	if (arg->flags[MINUS])
		return (ft_is_s_right(malloc_size, malloc_size - n, \
					str, ft_set_zero(arg)));
	else
		return (ft_is_s_left(malloc_size, n, str, ft_set_zero(arg)));
}

static char		*ft_unicode_prec_width(t_params *arg, int len, char *new)
{
	int			malloc_size;
	int			n;

	n = 0;
	malloc_size = ft_prec_s(0, len, arg);
	malloc_size = ft_malloc_width_s(malloc_size, &n, arg);
	if (arg->flags[MINUS])
		return (ft_is_s_perc_right(malloc_size, malloc_size - n,
					new, ft_set_zero(arg)));
	else
		return (ft_is_s_perc_left(malloc_size, n, new, ft_set_zero(arg)));
}

static char		*ft_unicode_converter(t_params *arg, wchar_t *wstr, int len)
{
	char		*new;
	int			i;
	int			j;
	int			tmp;

	i = 0;
	j = 0;
	new = NULL;
	tmp = (arg->flags[PREC]) ? arg->prec : 0;
	while (i < len)
	{
		if (arg->flags[ERR] == 1)
		{
			free(new);
			return (NULL);
		}
		else
		{
			new = ft_strjoin_clr(new, ft_is_unicode_c(arg, (int)wstr[j]), 2);
			i += ft_wcharlen(wstr[j]);
			j++;
		}
	}
	arg->prec = tmp;
	return (ft_unicode_prec_width(arg, ft_strlen(new), new));
}

static char		*ft_is_unicode_s(t_params *arg, va_list lst)
{
	wchar_t		*wstr;
	char		*str;

	str = NULL;
	wstr = ft_prop_cast_s(arg, lst);
	if (wstr == NULL)
	{
		return (str = ft_strdup("(null)"));
	}
	if (ft_wstrlen(wstr) == -1)
	{
		arg->flags[ERR] = 1;
		return (NULL);
	}
	return (ft_unicode_converter(arg, wstr, ft_wstrlen(wstr)));
}

char			*ft_is_s(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (ft_is_unicode_s(arg, lst));
	else
		return (ft_is_normal_s(arg, lst));
}
