/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/31 11:42:33 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 19:23:42 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_is_normal_c(t_params *arg, int var)
{
	char		c;

	c = (char)var;
	if (arg->flags[MINUS])
	{
		if (c == 0)
			c = -8;
		return (ft_prepend(ft_malloc_width_c(arg), 1, c));
	}
	else
	{
		if (c == 0)
			c = -8;
		return (ft_append(ft_malloc_width_c(arg), 1, c));
	}
}

char			*ft_is_c(t_params *arg, va_list lst)
{
	int			var;

	var = ft_prop_cast_c(arg, lst);
	if (var <= 255)
		return (ft_is_normal_c(arg, var));
	return (ft_is_unicode_c(arg, var));
}

char			*ft_is_cap_c(t_params *arg, va_list lst)
{
	arg->flags[L] = 1;
	return (ft_is_c(arg, lst));
}
