/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:28:47 by juspende          #+#    #+#             */
/*   Updated: 2017/11/18 17:47:55 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		t_flag
{
	int		neg;
	int		pos;
	int		space;
	int		zero;
	int		diez;
}					t_flag;

int			ft_atoi(const char *str);
void		ft_print_adress(void *buf);
void		ft_print_bits(void *buf);
void		ft_putnbr_base(int nbr, char *base);
void		ft_putshort(short int nb);
char		*ft_strnew(size_t size);
int			ft_printf(const char *list, ...);
void		ft_putstr(const char *str);
void		ft_putchar(char c);
void		ft_putint(int n);
void		ft_putuint(unsigned int nb);
void		ft_putlong(long nb);
void		ft_putdouble(double nb, int index);
int			arg_parser(va_list argp, const char *arg, int *index, t_flag *flag);
void		init_struct(t_flag *flag);
char		*ft_itoa(int nb);
char		*ft_itoa_double(double nb, int index);
int			flag_parser(va_list argp, const char *arg, int *index, t_flag *flag);
int			a(va_list argp, const char *arg, int *index, t_flag *flag);
int			b(va_list argp, const char *arg, int *index, t_flag *flag);
int			c(va_list argp, const char *arg, int *index, t_flag *flag);
int			d(va_list argp, const char *arg, int *index, t_flag *flag);
int			e(va_list argp, const char *arg, int *index, t_flag *flag);
int			f(va_list argp, const char *arg, int *index, t_flag *flag);
int			g(va_list argp, const char *arg, int *index, t_flag *flag);
int			h(va_list argp, const char *arg, int *index, t_flag *flag);
int			i(va_list argp, const char *arg, int *index, t_flag *flag);
int			j(va_list argp, const char *arg, int *index, t_flag *flag);
int			k(va_list argp, const char *arg, int *index, t_flag *flag);
int			l(va_list argp, const char *arg, int *index, t_flag *flag);
int			m(va_list argp, const char *arg, int *index, t_flag *flag);
int			n(va_list argp, const char *arg, int *index, t_flag *flag);
int			o(va_list argp, const char *arg, int *index, t_flag *flag);
int			p(va_list argp, const char *arg, int *index, t_flag *flag);
int			q(va_list argp, const char *arg, int *index, t_flag *flag);
int			r(va_list argp, const char *arg, int *index, t_flag *flag);
int			s(va_list argp, const char *arg, int *index, t_flag *flag);
int			t(va_list argp, const char *arg, int *index, t_flag *flag);
int			u(va_list argp, const char *arg, int *index, t_flag *flag);
int			v(va_list argp, const char *arg, int *index, t_flag *flag);
int			w(va_list argp, const char *arg, int *index, t_flag *flag);
int			x(va_list argp, const char *arg, int *index, t_flag *flag);
int			y(va_list argp, const char *arg, int *index, t_flag *flag);
int			z(va_list argp, const char *arg, int *index, t_flag *flag);

#endif
