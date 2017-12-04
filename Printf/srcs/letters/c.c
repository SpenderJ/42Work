/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/04 10:05:04 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static int	big_c(va_list argp, const char *arg, int *index, t_flag *flag)
{
	wint_t		*s;
	int			i;

	i = -1;
	if ((s = malloc(sizeof(wint_t) * (2))) == NULL)
		return (0);
	s[0] = va_arg(argp, wint_t);
	s[1] = '\0';
	if (ft_wstrlen(s[0]) == -1 && (flag->instantquit = LEAVE))
		return (0);
	while (s && s[++i])
		ft_putchar_s(s[i], flag);
	larg_flag_after(flag);
	return (0);
}

int		c(va_list argp, const char *arg, int *index, t_flag *flag)
{
	unsigned char	i;

	flag->larg = flag->larg - 1;
	if (arg[0] == 'C')
		return (big_c(argp, arg, index, flag));
	larg_flag_before(flag);
	i = va_arg(argp, int);
	if (i == 0)
	{
		write(1, flag->printed, flag->charn);
		write(1, &i, 1);
		flag->charn += 1;
		free (flag->printed);
		flag->printed = ft_strnew(2);
	}
	else if(arg[0] == 'C' || flag->l)
		ft_putchar(i, flag);
	else
		ft_printchar(i, flag);
	larg_flag_after(flag);
	return (0);
}
