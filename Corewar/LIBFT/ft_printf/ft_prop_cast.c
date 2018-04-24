/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prop_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:53:44 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 14:58:42 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_prop_cast_signed(t_params *arg, va_list lst)
{
	if (arg->flags[J])
		return (va_arg(lst, intmax_t));
	else if (arg->flags[Z])
		return (va_arg(lst, size_t));
	else if (arg->flags[LL])
		return (va_arg(lst, long long));
	else if (arg->flags[L])
		return (va_arg(lst, long));
	else if (arg->flags[H])
		return ((short)va_arg(lst, int));
	else if (arg->flags[HH])
		return ((char)va_arg(lst, int));
	return (va_arg(lst, int));
}

unsigned long long	ft_prop_cast_unsigned(t_params *arg, va_list lst)
{
	if (arg->flags[J])
		return (va_arg(lst, uintmax_t));
	else if (arg->flags[Z])
		return (va_arg(lst, size_t));
	else if (arg->flags[LL])
		return (va_arg(lst, unsigned long long));
	else if (arg->flags[L])
		return (va_arg(lst, unsigned long));
	else if (arg->flags[H])
		return ((unsigned short)va_arg(lst, unsigned int));
	else if (arg->flags[HH])
		return ((unsigned char)va_arg(lst, unsigned int));
	return (va_arg(lst, unsigned int));
}

void				*ft_prop_cast_s(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (va_arg(lst, wchar_t *));
	else
		return (va_arg(lst, char *));
}

int					ft_prop_cast_c(t_params *arg, va_list lst)
{
	if (arg->flags[L])
		return (va_arg(lst, wint_t));
	else
		return (va_arg(lst, int));
}
