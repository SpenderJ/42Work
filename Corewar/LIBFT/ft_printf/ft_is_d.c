/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 14:26:59 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 19:57:24 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_d_pos(t_params *arg, char *s1, char *s2, long long number)
{
	if (arg->flags[ZERO])
		s2 = ft_prepend(s2, 1, '-');
	else if (number < -9223372036854775807)
		;
	else
		s1 = ft_prepend(s1, 1, '-');
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}

static char		*ft_d_neg(t_params *arg, char *s1, char *s2)
{
	if (arg->flags[PLUS] && arg->flags[ZERO])
		s2 = ft_prepend(s2, 1, '+');
	else if (arg->flags[PLUS] && !arg->flags[ZERO])
		s1 = ft_prepend(s1, 1, '+');
	else if (arg->flags[SPACE] && arg->flags[ZERO])
		s2 = ft_prepend(s2, 1, ' ');
	else if (arg->flags[SPACE] && !arg->flags[ZERO])
		s1 = ft_prepend(s1, 1, ' ');
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}

char			*ft_is_d(t_params *arg, va_list lst)
{
	long long	number;
	char		*s1;
	char		*s2;
	int			lstr;
	char		*str;

	number = ft_prop_cast_signed(arg, lst);
	str = ft_lltoa_base((long long)(ft_abs_ll(number)), "0123456789");
	ft_override_params_d(arg, number);
	s1 = ft_malloc_prec_dux(str, arg);
	free(str);
	lstr = (number < 0) ? ft_strlen(s1) + 1 : ft_strlen(s1);
	s2 = ft_malloc_width_dopux(lstr, arg);
	if (number < 0)
		return (ft_d_pos(arg, s1, s2, number));
	return (ft_d_neg(arg, s1, s2));
}

char			*ft_is_cap_d(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_d(arg, lst));
}

char			*ft_is_i(t_params *arg, va_list lst)
{
	return (ft_is_d(arg, lst));
}
