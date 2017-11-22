/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 09:17:45 by alucas-           #+#    #+#             */
/*   Updated: 2017/11/22 17:01:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	ft_putnbr_base_n(long nbr, char *base, int n, t_flag *flag)
{
	int i;

	i = 0;
	if (nbr < 0)
	{
		++i;
		ft_putchar('-', flag);
		i += ft_putnbr_base_n(-nbr, base, n, flag);
	}
	else if (nbr < n)
	{
		++i;
		ft_putchar(base[nbr], flag);
	}
	else
	{
		++i;
		i += ft_putnbr_base_n(nbr / n, base, n, flag);
		ft_putchar(base[nbr % n], flag);
	}
	return (i);
}

static int	ft_print_memstr(char *ptr, int i, int len, t_flag *flag)
{
	int		c;

	c = 0;
	if (i++ < len)
	{
		c = ft_putnbr_base_n((int)ptr[i - 1], "0123456789abcdef", 16, flag);
		if (i++ < len)
			c += ft_putnbr_base_n((int)ptr[i - 1], "0123456789abcdef", 16,
					flag);
	}
	else
		++i;
	while (c < 5)
	{
		ft_putchar(' ', flag);
		++c;
	}
	return (i);
}

static void	ft_print_mem_line(char *ptr, int len, t_flag *flag)
{
	int		i;

	ft_putnbr_base_n((long)(void *)ptr, "0123456789abcdef", 16, flag);
	return ;
	ft_putchar(':', flag);
	ft_putchar(' ', flag);
	i = 0;
	while (i < 16)
		i = ft_print_memstr(ptr, i, len, flag);
	i = -1;
	while (++i < 16)
		if (i < len)
			ft_putchar((int)ptr[i] > 31 && (int)ptr[i] != 2032 ? ptr[i] : '.',
					flag);
	ft_putchar('\n', flag);
}

void		*ft_print_memory(void *addr, unsigned int size, t_flag *flag)
{
	int		i;
	int		len;

	i = 0;
	ft_putstr("0x", flag);
	while (i < (int)size)
	{
		len = size - i;
		ft_print_mem_line((char *)(addr + i), len > 16 ? 16 : len, flag);
		i += 16;
	}
	return (addr);
}
