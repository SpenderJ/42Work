/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 18:18:23 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void		larg_flag_before_d(t_flag *flag)
{
	char	*str;
	int		i;

	i = -1;
	flag->space && flag->nbr > 0 ? flag->larg -= 1 : (int)flag;
	flag->pos && flag->nbr > 0 ? flag->larg -= 1 : (int)flag;
	if ((str = malloc(sizeof(char) * (flag->larg > flag->point ? flag->larg + flag->tilt : flag->point))) == NULL)
		return ;
	flag->zero ? (flag->c = '0') : (flag->c = ' ');
	flag->space && flag->nbr > 0 ? (str[++i] = ' ') : (int)flag;
	if (!flag->neg && !flag->zero && flag->larg > flag->point && flag->nbr > 0 && flag->larg  > flag->tilt)
		while (flag->larg-- > (flag->point > flag->tilt ? flag->point : flag->tilt))
			str[++i] = flag->c;
	flag->nbr < 0 ? str[++i] = '-' : (int)flag;
	flag->nbr >= 0 && flag->pos ? str[++i] = '+' : (int)flag;
	larg_flag_before_d2(flag, str, i);
}

void		larg_flag_before_d2(t_flag *flag, char *str, int i)
{
	int		c;

	c = -1;
	if (flag->neg && flag->point > flag->tilt)
		while (flag->point-- > flag->tilt)
			str[++i] = '0';
	flag->larg += flag->tilt;
	if (flag->neg)
		return ;
	if (flag->larg > flag->point && flag->larg > flag->tilt)
		while (flag->larg-- > (flag->point > flag->tilt ? flag->point : flag->tilt))
			str[++i] = flag->c;
	if (flag->point >flag->tilt)
		while (flag->point-- > flag->tilt)
			str[++i] = '0';
	str[++i] = '\0';
	ft_putnstr(str, flag, &c);
}

void		larg_flag_after_d(t_flag *flag)
{
	char	*str;
	int		i;
	int		c;

	i = -1;
	c = -1;
	if (!flag->neg)
		return ;
	if ((str = malloc(sizeof(char) * (flag->larg + 1))) == NULL)
		return ;
	while (flag->larg-- > (flag->tilt > flag->point ? flag->tilt : flag->point))
		str[++i] = flag->c;
	str[++i] = '\0';
	ft_putnstr(str, flag, &c);
}

int			d(va_list argp, const char *arg, int *index, t_flag *flag)
{
	intmax_t		tmp;
	int				c;
	int				neg;

	arg[0] == 'D' ? flag->l = 1 : (int)flag;
	neg = ((int)index & 0);
	c = -1;
	length_modif_di(argp, flag, &tmp);
	flag->tilt = int_len(tmp);
	flag->larg -= int_len(tmp);
	flag->nbr = tmp;
	larg_flag_before_d(flag);
	ft_putnstr(ft_itoa(tmp, 10), flag, &c);
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
	else
		return (1);
}
