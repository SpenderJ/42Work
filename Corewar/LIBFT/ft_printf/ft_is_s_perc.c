/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_s_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:47:25 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/25 14:13:13 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_is_s_perc(t_params *arg, char *format)
{
	int			malloc_size;
	int			width;
	int			n;
	char		*str;

	arg->flags[PREC] = 0;
	if (arg->flags[MINUS])
		arg->flags[ZERO] = 0;
	str = ft_strndup(format, 1);
	if (str == NULL)
		str = ft_strdup("(null)");
	width = arg->width;
	n = 0;
	malloc_size = ft_prec_s(0, ft_strlen(str), arg);
	malloc_size = ft_malloc_width_s(malloc_size, &n, arg);
	if (arg->flags[MINUS])
		return (ft_is_s_perc_right(malloc_size, malloc_size - n, \
			str, ft_set_zero(arg)));
	else
		return (ft_is_s_perc_left(malloc_size, n, str, ft_set_zero(arg)));
}
