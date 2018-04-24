/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 10:37:46 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 14:56:44 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_params(t_params *arg)
{
	ft_printf("%c : %d\n", '#', arg->flags[0]);
	ft_printf("%c : %d\n", '+', arg->flags[1]);
	ft_printf("%c : %d\n", '-', arg->flags[2]);
	ft_printf("%c : %d\n", ' ', arg->flags[3]);
	ft_printf("%c : %d\n", '0', arg->flags[4]);
	ft_printf("%c : %d\n", 'h', arg->flags[5]);
	ft_printf("%c : %d\n", 'l', arg->flags[6]);
	ft_printf("%c : %d\n", 'j', arg->flags[7]);
	ft_printf("%c : %d\n", 'z', arg->flags[8]);
	ft_printf("%s : %d\n", "hh", arg->flags[9]);
	ft_printf("%s : %d\n", "ll", arg->flags[10]);
	ft_printf("%s : %d\n", "err", arg->flags[11]);
	ft_printf("%s : %d\n", "precision (flag)", arg->flags[11]);
	ft_printf("width = %d\n", arg->width);
	ft_printf("precision = %d\n", arg->prec);
}

static void	ft_check_if_null(char *str, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (str[i] == -8)
			str[i] = 0;
		i++;
	}
}

int			ft_print_buffer(char *str, int err, int fd)
{
	int		n;

	if (err == -1)
	{
		free(str);
		return (-1);
	}
	else
	{
		n = ft_strlen(str);
		ft_check_if_null(str, n);
		write(fd, str, n);
		free(str);
	}
	return (n);
}
