/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/04 10:06:25 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	cap_s_parser(t_flag *flag)
{
	if (flag->comma && !flag->point)
		flag->tilt = 0;
	flag->point -= flag->tilt;
	flag->charn += flag->tilt;
	flag->larg -= flag->tilt;
	if (flag->point < 0)
		flag->point = 0;
	flag->larg -= flag->point;
}

void		empty_buffer(t_flag *flag)
{
	write(1, flag->printed, ft_strlen(flag->printed));
	free (flag->printed);
	flag->printed = ft_strnew(2);
	return ;
}

static int	big_s(va_list argp, const char *arg, int *index, t_flag	 *flag)
{
	wint_t		*tmp;
	int			i;
	int			b;
	int			size;

	i = -1;
	b = 0;
	size = 0;
	(void)index;
	(void)arg;
	tmp = va_arg(argp, wint_t*);
	while (tmp && b != -1 && tmp[++i])
		ft_wstrlen(tmp[i]) == -1 ? b = -1 : (size += ft_wstrlen(tmp[i]));
	if (b == -1 && (flag->instantquit = LEAVE))
		return (0);
	flag->comma && !flag->point ? (flag->tilt = 0) : (flag->tilt = size);
	cap_s_parser(flag);
	i = -1;
	flag->comma && !flag->point ? (b = -1) : b;
//	printf("flag->larg = %d, flag->point = %d, flag->tilt = %d, flag->charn = %d\n", flag->larg, flag->point, flag->tilt, flag->charn);
	larg_flag_before_s(flag);
	while (tmp && tmp[++i] && b >= 0 && flag->tilt != 0)
		ft_putchar_s(tmp[i], flag);
	!tmp ? ft_puts("(null)", flag) : flag;
	larg_flag_after_s(flag);
	return (0);
}

int		s(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	*tmp;
	int		i;
	int		b;

	i = -1;
	b = 0;
	if (arg[0] == 'S')
		return (big_s(argp, arg, index, flag));
	tmp = va_arg(argp, char*);
	if (!tmp && !flag->comma)
		tmp = ft_strdup("(null)");
	if (flag->larg != 0 && (int)ft_strlen(tmp) > flag->larg)
		tmp[flag->larg] = '\0';
	if (flag->comma && (int)ft_strlen(tmp) > flag->point && flag->point > 0)
		tmp[flag->point] = '\0';
	if (flag->comma && !flag->point && (b = -1))
		;
	flag->larg = flag->larg - ft_strlen(tmp);
	larg_flag_before(flag);
	if (b != -1)
		ft_putnstr(tmp, flag, &i);
	if (b == -1 && tmp && tmp[0] != '0')
		ft_printchar('0', flag);
	larg_flag_after(flag);
	return (0);
}
