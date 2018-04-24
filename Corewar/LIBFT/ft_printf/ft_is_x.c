/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 22:35:17 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:16:49 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				*b_x(char *s, int h, t_params *a, unsigned long long n)
{
	char				*s2;

	s2 = ft_malloc_width_dopux(ft_strlen(s) + h, a);
	if (a->flags[HASH] && n != 0)
	{
		if (a->flags[ZERO])
			s2 = ft_strjoin_clr("0x", s2, 1);
		else
		{
			if (a->flags[MINUS])
				s = ft_strjoin_clr("0x", s, 1);
			else
				s2 = ft_strjoin_clr(s2, "0x", 0);
		}
	}
	if (a->flags[MINUS])
		return (ft_strjoin_clr(s, s2, 2));
	else
		return (ft_strjoin_clr(s2, s, 2));
}

static char				*b_cx(char *s, int h, t_params *a, unsigned long long n)
{
	char				*s2;

	s2 = ft_malloc_width_dopux(ft_strlen(s) + h, a);
	if (a->flags[HASH] && n != 0)
	{
		if (a->flags[ZERO])
			s2 = ft_strjoin_clr("0X", s2, 1);
		else
		{
			if (a->flags[MINUS])
				s = ft_strjoin_clr("0X", s, 1);
			else
				s2 = ft_strjoin_clr(s2, "0X", 0);
		}
	}
	if (a->flags[MINUS])
		return (ft_strjoin_clr(s, s2, 2));
	else
		return (ft_strjoin_clr(s2, s, 2));
}

char					*ft_is_x(t_params *arg, va_list lst)
{
	unsigned long long	number;
	char				*s1;
	int					hash;
	char				*str;

	hash = 0;
	number = ft_prop_cast_unsigned(arg, lst);
	str = ft_llutoa_base(number, "0123456789abcdef");
	if (arg->flags[ZERO] && arg->prec == 0 && arg->flags[PREC])
		arg->flags[ZERO] = 0;
	s1 = ft_malloc_prec_dux(str, arg);
	free(str);
	if (arg->flags[HASH] && number != 0)
		hash = 2;
	return (b_x(s1, hash, arg, number));
}

char					*ft_is_cap_x(t_params *arg, va_list lst)
{
	unsigned long long	number;
	char				*s1;
	int					hash;
	char				*str;

	hash = 0;
	number = ft_prop_cast_unsigned(arg, lst);
	str = ft_llutoa_base(number, "0123456789ABCDEF");
	if (arg->flags[ZERO] && arg->prec == 0 && arg->flags[PREC])
		arg->flags[ZERO] = 0;
	s1 = ft_malloc_prec_dux(str, arg);
	free(str);
	if (arg->flags[HASH] && number != 0)
		hash = 2;
	return (b_cx(s1, hash, arg, number));
}
