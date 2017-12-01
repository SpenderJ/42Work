/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 14:28:47 by juspende          #+#    #+#             */
/*   Updated: 2017/12/01 11:53:11 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define LLNEGMAX -9223372036854775807

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <inttypes.h>

typedef struct		t_flag
{
	int			neg;
	int			pos;
	int			space;
	int			zero;
	int			diez;
	int			comma;
	int			point;
	int			larg;
	int			charn;
	int			h;
	int			hh;
	int			ll;
	int			l;
	int			j;
	int			z;
	int			tilt;
	intmax_t	nbr;
	char		c;
	int			cpy;
	char		*printed;
}					t_flag;

void		larg_flag_after_d(t_flag *flag);
void		larg_flag_before_d2(t_flag *flag, char *str, int i);
void		larg_flag_before_d(t_flag *flag);
int			ft_uintlen(uintmax_t n, int base);
int			ft_uintstr(char *dst, uintmax_t n, int base);
char		*ft_strcat(char *dest, char *src);
char		*ft_strncat(char *dest, char *src, size_t len);
int			ft_strchr(const char *str, int c);
void		ft_putnstr(void *str, t_flag *flag, int *c);
int			free_main(t_flag *flag, int returned);
void		free_tab(char **tab);
int			int_len(intmax_t nbr);
int			int_len2(uintmax_t nbr);
void		length_modif_uox(va_list argp, t_flag *flag, uintmax_t *tmp);
void		length_modif_di(va_list argp, t_flag *flag, intmax_t *tmp);
void		larg_flag_before(t_flag *flag);
void		larg_flag_after(t_flag *flag);
size_t		ft_strlen(char *str);
char		*ft_strdup(const char *str);
char		*ft_getnbr_base(intmax_t nbr, char *base);
char		*ft_getnbr_base_ui(uintmax_t nbr, char *base);
char		*ft_strrev(char *str);
int			precision_pars(va_list argp, const char *arg, int *index, t_flag *flag);
void		*ft_print_memory(void *addr, unsigned int size, t_flag *flag);
int			ft_atoi(const char *str);
void		ft_print_adress(void *buf, t_flag *flag);
void		ft_print_bits(void *buf, t_flag *flag);
void		ft_putnbr_base(int nbr, char *base, t_flag *flag);
void		ft_putshort(short int nb, t_flag *flag);
char		*ft_strnew(size_t size);
int			ft_printf(const char *list, ...);
void		ft_putstr(const char *str, t_flag *flag);
void		ft_putoctal(const char *str, t_flag *flag);
void		ft_putchar(wchar_t c, t_flag *flag);
void		ft_printchar(char c, t_flag *flag);
void		ft_putint(intmax_t n, t_flag *flag);
void		ft_putuint(uintmax_t nb, t_flag *flag);
void		ft_putlong(long nb, t_flag *flag);
void		ft_putdouble(double nb, int index, t_flag *flag);
int			arg_parser(va_list argp, const char *arg, int *index, t_flag *flag);
int			init_struct(t_flag *flag);
char		*ft_itoa(uintmax_t n, int base);
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
int			(*g_letter_parser[26])(va_list, const char*, int*, t_flag*);

#endif
