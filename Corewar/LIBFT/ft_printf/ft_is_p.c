/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 22:19:43 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 18:21:14 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char			*ft_is_p_one(t_params *arg, unsigned long long number)
{
	char				*s1;
	char				*s2;
	int					lstr;
	char				*str;

	str = ft_llutoa_base(number, "0123456789abcdef");
	s1 = ft_malloc_prec_p(str, arg);
	free(str);
	s1 = ft_strjoin_clr("0x", s1, 1);
	lstr = ft_strlen(s1);
	s2 = ft_malloc_width_dopux(lstr, arg);
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}

static	char			*ft_is_p_two(t_params *arg, unsigned long long number)
{
	char				*s1;
	char				*s2;
	int					lstr;
	char				*str;

	str = ft_llutoa_base(number, "0123456789abcdef");
	s1 = ft_malloc_prec_p(str, arg);
	free(str);
	lstr = ft_strlen(s1);
	s2 = ft_malloc_width_dopux(lstr + 2, arg);
	s2 = ft_strjoin_clr("0x", s2, 1);
	return (ft_strjoin_clr(s2, s1, 2));
}

char					*ft_is_p(t_params *arg, va_list lst)
{
	unsigned long long	number;

	arg->flags[LL] = 1;
	number = ft_prop_cast_unsigned(arg, lst);
	if (arg->flags[ZERO] && arg->width > 0 && arg->flags[MINUS] == 0)
		return (ft_is_p_two(arg, number));
	else
		return (ft_is_p_one(arg, number));
}
