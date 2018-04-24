/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 15:52:33 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 19:25:34 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_is_u(t_params *arg, va_list lst)
{
	unsigned long long	number;
	char				*s1;
	char				*s2;
	char				*str;

	number = ft_prop_cast_unsigned(arg, lst);
	str = ft_llutoa(number);
	s1 = ft_malloc_prec_dux(str, arg);
	free(str);
	if (arg->flags[PREC])
		arg->flags[ZERO] = 0;
	s2 = ft_malloc_width_dopux(ft_strlen(s1), arg);
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 2));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}

char					*ft_is_cap_u(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_u(arg, lst));
}
