/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:48:38 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 14:57:00 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		lst;
	int			n;

	va_start(lst, format);
	n = ft_read_format((char *)format, lst, 1);
	va_end(lst);
	return (n);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list		lst;
	int			n;

	va_start(lst, format);
	n = ft_read_format((char *)format, lst, fd);
	va_end(lst);
	return (n);
}
