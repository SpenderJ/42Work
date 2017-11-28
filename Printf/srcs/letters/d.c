/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 17:02:47 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	larg_flag_before_d(t_flag *flag)
{
	flag->c = ' ';
	if (flag->neg && flag->point && (flag->larg -= flag->point) != -9)
	{
		flag->pos && flag->nbr >= 0 ? ft_putchar('+', flag) : flag->c;
		while (flag->point-- > flag->tilt)
			ft_putchar('0', flag);
		return (flag->space && flag->nbr >= 0 && !flag->pos ?
		ft_putchar(' ', flag) : flag->c);
	}
	else if (flag->neg)
		return ;
	flag->pos && flag->nbr >= 0 && flag->zero ? ft_putchar('+', flag) : flag;
	flag->space && flag->nbr >= 0 && !flag->pos && flag->zero ?
	ft_putchar(' ', flag) : flag->c;
	flag->zero && !flag->comma ? (flag->c = '0') : flag->c;
	flag->zero && flag->comma ? (flag->point--) && (flag->larg--) : flag->c;
	flag->comma ? flag->larg += flag->tilt : flag->c;
	flag->comma && !flag->zero && flag->nbr < 0 ? ft_putchar('-', flag) : c;
	while (flag->larg-- > flag->point)
		ft_putchar(flag->c, flag);
	flag->pos && flag->nbr >= 0 && !flag->zero ? ft_putchar('+', flag)
	: flag->c;
	flag->space && flag->nbr >= 0 && !flag->zero && !flag->pos ?
	ft_putchar(' ', flag) : flag->c;
	while (flag->point-- > flag->tilt)
		ft_putchar('0', flag);
}

static void	larg_flag_after_d(t_flag *flag)
{
	int			i;
	char		c;

	i = 0;
	c = ' ';
	if (!flag->neg)
		return ;
	if (flag->point)
		c = '0';
	if (flag->comma)
		flag->larg += flag->tilt;
	while (i < flag->larg)
	{
		++i;
		ft_putchar(' ', flag);
	}
}

int			d(va_list argp, const char *arg, int *index, t_flag *flag)
{
	intmax_t		tmp;
	int				c;
	int				neg;

	arg[0] == 'D' ? flag->l = 1 : (int)flag;
	neg = ((int)index & 0);
	length_modif_di(argp, flag, &tmp);
	flag->comma && flag->point > flag->larg ? flag->larg = flag->point :
	flag->larg;
	(c = 1) == 1 && flag->pos == 1 && tmp >= 0 ? --flag->larg : flag->larg;
	flag->space && tmp >= 0 ? --flag->larg : flag->larg;
	tmp < 0 ? --flag->larg : (neg = 84);
	flag->tilt = int_len(tmp);
	flag->larg -= int_len(tmp);
	flag->nbr = tmp;
	tmp < 0 && flag->zero ? ft_putchar('-', flag) : (neg = 9);
	tmp < 0 && tmp > -9223372036854775807 ? tmp *= -1 : (neg = 128);
	larg_flag_before_d(flag);
	neg != 128 && !flag->zero && !flag->comma ? ft_putchar('-', flag) : neg;
	tmp < -9223372036854775807 ? ft_putstr("-9223372036854775808", flag) :
	ft_putint(tmp, flag);
	larg_flag_after_d(flag);
	return (0);
}

int			int_len(intmax_t nbr)
{
	uintmax_t	tmp;

	if (nbr < 0)
		tmp = (uintmax_t)-nbr;
	else
		tmp = (uintmax_t)nbr;
	if (tmp >= 1000000000000000000)
		return (19);
	else if (tmp >= 100000000000000000)
		return (18);
	else if (tmp >= 10000000000000000)
		return (17);
	else if (tmp >= 1000000000000000)
		return (16);
	else if (tmp >= 100000000000000)
		return (15);
	else if (tmp >= 10000000000000)
		return (14);
	else if (tmp >= 1000000000000)
		return (13);
	else if (tmp >= 100000000000)
		return (12);
	else if (tmp >= 10000000000)
		return (11);
	return (int_len2(tmp));
}

int			int_len2(uintmax_t nbr)
{
	if (nbr >= 1000000000)
		return (10);
	else if (nbr >= 100000000)
		return (9);
	else if (nbr >= 10000000)
		return (8);
	else if (nbr >= 1000000)
		return (7);
	else if (nbr >= 100000)
		return (6);
	else if (nbr >= 10000)
		return (5);
	else if (nbr >= 1000)
		return (4);
	else if (nbr >= 100)
		return (3);
	else if (nbr >= 10)
		return (2);
	else if (nbr > 1)
		return (1);
	else
		return (0);
}
