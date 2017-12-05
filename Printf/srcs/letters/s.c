/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:18:40 by juspende          #+#    #+#             */
/*   Updated: 2017/12/05 15:22:08 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

static void	cap_s_parser(t_flag *flag)
{
	if (flag->comma && !flag->point)
		flag->tilt = 0;
	flag->charn += flag->tilt;
	flag->larg -= flag->tilt;
//	if (flag->point)
//		flag->larg += 1;
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
//	if (flag->comma && flag->point && flag->larg)
//		flag->charn -= 1;
	flag->point > 0 ? (flag->nbr = flag->point) : (flag->nbr = size);
	flag->comma && !flag->point ? (flag->tilt = 0) : (flag->tilt = flag->nbr);
	i = -1;
	cap_s_parser(flag);
//	printf("Flag->point = %d, flag->nbr = %d, flag->larg = %d, flag->tilt = %d\n", flag->point, flag->nbr, flag->larg, flag->tilt);
	flag->comma && !flag->nbr ? (b = -1) : b;
	flag->point <= 0 ? (flag->point = flag->tilt) : flag->point;
	larg_flag_before_s(flag);
	size = 0;
	while (tmp && (size += ft_wstrlen(tmp[++i])) && size <= flag->nbr && tmp[i] && b >= 0 && flag->tilt != 0)
		ft_putchar_s(tmp[i], flag);
//	printf("Size = %d\n", size - ft_wstrlen(tmp[i]));
	if (tmp && flag->tilt != 0 && b >= 0 && size - ft_wstrlen(tmp[i]) < flag->tilt)
		flag->charn -= (flag->nbr - (size - ft_wstrlen(tmp[i])));
	!tmp ? ft_puts("(null)", flag) : flag;
	larg_flag_after_s(flag);
	empty_buffer(flag);
	return (0);
}

int		s(va_list argp, const char *arg, int *index, t_flag *flag)
{
	char	*tmp;
	int		i;
	int		b;

	i = -1;
	b = 0;
	if (arg[0] == 'S' || flag->l)
		return (big_s(argp, arg, index, flag));
	tmp = va_arg(argp, char*);
	if (!tmp && !flag->comma)
		tmp = ft_strdup("(null)");
	else
		tmp = ft_strdup(tmp);
//	if (flag->larg > 0 && (int)ft_strlen(tmp) > flag->larg)
//		tmp[flag->larg] = '\0';
	if (flag->comma && (int)ft_strlen(tmp) > flag->point && flag->point > 0)
		tmp[flag->point] = '\0';
	if (flag->comma && !flag->point && (b = -1))
		;
	flag->larg = flag->larg - ft_strlen(tmp);
	larg_flag_before(flag);
	if (b != -1)
		ft_putnstr(tmp, flag, &i);
//	if (b == -1 && tmp && tmp[0] != '0')
//		ft_printchar('0', flag);
	if (b == -1 && (b = ft_strlen(tmp)))
		while (b-- > 0)
			ft_putchar(' ', flag);
	larg_flag_after(flag);
	return (0);
}
