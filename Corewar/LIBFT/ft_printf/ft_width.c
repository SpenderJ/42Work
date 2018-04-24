/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 18:49:01 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 19:01:21 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			ft_set_zero(t_params *arg)
{
	if (arg->flags[ZERO])
		return ('0');
	return (' ');
}

char			*ft_malloc_width_dopux(int n, t_params *arg)
{
	char			*str;
	int				i;
	char			c;

	n = arg->width - arg->flags[SPACE] - arg->flags[PLUS] - n;
	c = (arg->flags[ZERO]) ? '0' : ' ';
	i = 0;
	if (n < 0)
		n = 0;
	str = (char *)malloc(n + 1);
	if (str)
	{
		while (i < n)
		{
			str[i] = c;
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

int				ft_malloc_width_s(int malloc_size, int *n, t_params *arg)
{
	if (arg->width > malloc_size)
	{
		*n = arg->width - malloc_size;
		malloc_size = arg->width;
	}
	return (malloc_size);
}

char			*ft_malloc_width_c(t_params *arg)
{
	char		*str;
	int			i;
	char		c;

	i = 0;
	if (!arg->width)
		return (NULL);
	c = (arg->flags[ZERO]) ? '0' : ' ';
	str = (char *)malloc(arg->width - 1 + 1);
	if (str)
		while (i < arg->width - 1)
			str[i++] = c;
	return (str);
}
