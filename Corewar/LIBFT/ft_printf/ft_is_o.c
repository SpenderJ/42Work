/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 18:52:44 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 19:25:19 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_is_o(t_params *arg, va_list lst)
{
	unsigned long long	number;
	char				*s1;
	char				*s2;
	int					lstr;
	char				*str;

	number = ft_prop_cast_unsigned(arg, lst);
	str = ft_llutoa_base(number, "01234567");
	s1 = ft_malloc_prec_o(str, arg);
	free(str);
	lstr = ft_strlen(s1);
	if (arg->flags[HASH] && number != 0 && arg->prec == 0)
	{
		s1 = ft_prepend(s1, 1, '0');
		lstr++;
	}
	if (arg->flags[PREC])
		arg->flags[ZERO] = 0;
	s2 = ft_malloc_width_dopux(lstr, arg);
	if (arg->flags[MINUS])
		return (ft_strjoin_clr(s1, s2, 1));
	else
		return (ft_strjoin_clr(s2, s1, 2));
}

char					*ft_is_cap_o(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_o(arg, lst));
}
