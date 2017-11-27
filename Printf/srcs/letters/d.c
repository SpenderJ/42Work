/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/27 19:33:32 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	larg_flag_before_d(t_flag *flag)
{
	char		c;

	c = ' ';
	if (flag->neg != 0 && flag->point != 0)
	{
		flag->larg -= flag->point;
		(flag->pos != 0 && flag->nbr >= 0 ? ft_putchar('+', flag) : c);
		while (flag->point-- > flag->tilt)
			ft_putchar('0', flag);
		(flag->space != 0 && flag->nbr >= 0 && flag->pos == 0 ?
		 ft_putchar(' ', flag) : c);
		return ;
	}
	else if (flag->neg != 0)
		return ;
	(flag->pos != 0 && flag->nbr >= 0 && flag->zero != 0
	 ? ft_putchar('+', flag) : c);
	(flag->space != 0 && flag->nbr >= 0 && flag->pos == 0 && flag->zero != 0 ?
	 ft_putchar(' ', flag) : c);
	(flag->zero != 0 ? (c = '0') : c);
	(flag->comma != 0 ? flag->larg += flag->tilt : c);
	while (flag->larg-- > flag->point)
		ft_putchar(c, flag);
	(flag->pos != 0 && flag->nbr >= 0 && flag->zero == 0
	 ? ft_putchar('+', flag) : c);
	(flag->space != 0 && flag->nbr >= 0 && flag->zero == 0 && flag->pos == 0
	 ? ft_putchar(' ', flag) : c);
	while (flag->point-- > flag->tilt)
		ft_putchar('0', flag);
}

static void	larg_flag_after_d(t_flag *flag)
{
	int			i;
	char		c;

	i = 0;
	c = ' ';
	if (flag->neg == 0)
		return ;
	if (flag->point != 0)
		c = '0';
	if (flag->comma != 0)
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
	int				u;
	int				neg;

	u = ((int)arg & (int)index & 0);
	neg = 0;
	length_modif_di(argp, flag, &tmp);
	(flag->comma != 0 && flag->point > flag->larg ? flag->larg = flag->point :
	 flag->larg);
	((c = 1) == 1 && flag->pos == 1 && tmp >= 0 ? --flag->larg : flag->larg);
	(flag->space == 1 && tmp >= 0 ? --flag->larg : flag->larg);
	(tmp < 0 ? --flag->larg : (neg = 84));
	u = int_len(tmp);
	flag->tilt = u;
	flag->larg -= u;
	flag->nbr = tmp;
	(tmp >= 0 && flag->space == 1 && neg == 22 ? ft_putchar(' ', flag) : c);
	(tmp < 0 && flag->zero != 0 ? ft_putchar('-', flag) : (neg = 9));
	(tmp < 0 && tmp > -9223372036854775807 ? tmp *= -1 : (neg = 128));
	larg_flag_before_d(flag);
	(neg != 128 && flag->zero == 0 ? ft_putchar('-', flag) : (neg = 45));
	(tmp < -9223372036854775807 ? ft_putstr("-9223372036854775808", flag) :
	 ft_putint(tmp, flag));
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
	if (tmp > 1000000000000000000)
		return (19);
	else if (tmp > 100000000000000000)
		return (18);
	else if (tmp > 10000000000000000)
		return (17);
	else if (tmp > 1000000000000000)
		return (16);
	else if (tmp > 100000000000000)
		return (15);
	else if (tmp > 10000000000000)
		return (14);
	else if (tmp > 1000000000000)
		return (13);
	else if (tmp > 100000000000)
		return (12);
	else if (tmp > 10000000000)
		return (11);
	return (int_len2(tmp));
}

int			int_len2(uintmax_t nbr)
{
	if (nbr > 1000000000)
		return (10);
	else if (nbr > 100000000)
		return (9);
	else if (nbr > 10000000)
		return (8);
	else if (nbr > 1000000)
		return (7);
	else if (nbr > 100000)
		return (6);
	else if (nbr > 10000)
		return (5);
	else if (nbr > 1000)
		return (4);
	else if (nbr > 100)
		return (3);
	else if (nbr > 10)
		return (2);
	else if (nbr > 1)
		return (1);
	else
		return (0);
}
