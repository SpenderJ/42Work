/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:46:36 by vtennero          #+#    #+#             */
/*   Updated: 2018/01/30 15:01:22 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft.h"
# include <wchar.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <locale.h>

typedef int			t_bool;

enum
{
	HASH, PLUS, MINUS, SPACE, ZERO, H, L, J, Z, HH, LL, PREC, ERR
};

typedef struct		s_params
{
	int				width;
	int				prec;
	t_bool			flags[ERR + 1];
}					t_params;

typedef struct		s_struct
{
	char			*(*printfunc)(t_params *arg, va_list lst);
}					t_struct;

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
/*
** ------------------------- PARAMETERS CREATION -------------------------
*/
void				ft_set_g_formats(void);
int					ft_read_format(char *format, va_list lst, int fd);
t_params			*ft_create_params(void);
t_params			*ft_set_zero_params(t_params *arg);
/*
** ------------------------- PARAMETERS SETTINGS -------------------------
*/
int					ft_flwp(t_params *arg, char *format, int *i);
int					ft_set_flags(t_params *arg, char *str, int *index);
int					ft_set_length(t_params *arg, char *str, int *index);
int					ft_set_width(t_params *arg, char *str, int *index);
int					ft_set_prec(t_params *arg, char *str, int *index);
/*
** ------------------------- PARAMETERS OVERRIDE -------------------------
*/
t_params			*ft_general_overrides(t_params *arg);
void				ft_override_params_d(t_params *arg, long long nb);
void				ft_override_length(t_params *arg);
void				ft_is_z(t_params *arg);
void				ft_is_j(t_params *arg);
void				ft_is_ll(t_params *arg);
void				ft_is_l(t_params *arg);
void				ft_is_h(t_params *arg);
/*
** ------------------------- SPECIFIERS -------------------------
*/
char				*ft_is_s(t_params *arg, va_list lst);
char				*ft_is_cap_s(t_params *arg, va_list lst);
char				*ft_is_p(t_params *arg, va_list lst);
char				*ft_is_d(t_params *arg, va_list lst);
char				*ft_is_cap_d(t_params *arg, va_list lst);
char				*ft_is_i(t_params *arg, va_list lst);
char				*ft_is_o(t_params *arg, va_list lst);
char				*ft_is_cap_o(t_params *arg, va_list lst);
char				*ft_is_u(t_params *arg, va_list lst);
char				*ft_is_cap_u(t_params *arg, va_list lst);
char				*ft_is_x(t_params *arg, va_list lst);
char				*ft_is_cap_x(t_params *arg, va_list lst);
char				*ft_is_c(t_params *arg, va_list lst);
char				*ft_is_cap_c(t_params *arg, va_list lst);
char				*ft_is_s_perc(t_params *arg, char *format);
/*
** ------------------------- PROPER CAST -------------------------
*/
long long			ft_prop_cast_signed(t_params *arg, va_list lst);
unsigned long long	ft_prop_cast_unsigned(t_params *arg, va_list lst);
void				*ft_prop_cast_s(t_params *arg, va_list lst);
int					ft_prop_cast_c(t_params *arg, va_list lst);
/*
** ------------------------- PRINT -------------------------
*/
int					ft_print_buffer(char *str, int err, int fd);
void				ft_print_params(t_params *arg);
/*
** ------------------------- STRING MANIPULATION -------------------------
*/
char				*ft_is_s_left(int size, int n, char *str, char c);
char				*ft_is_s_right(int size, int n, char *str, char c);
char				*ft_is_s_perc_left(int size, int n, char *str, char c);
char				*ft_is_s_perc_right(int size, int n, char *str, char c);
char				*ft_append(char *buf, int n, char c);
char				*ft_prepend(char *buf, int n, char c);
char				*ft_is_unicode_c(t_params *arg, int var);
/*
** ------------------------- PRECISION -------------------------
*/
char				*ft_build_prec_str(int p, int len, char *str, char *s1);
char				*ft_malloc_prec_o(char *str, t_params *arg);
char				*ft_malloc_prec_p(char *str, t_params *arg);
int					ft_prec_s(int malloc_size, int str_length, t_params *arg);
char				*ft_malloc_prec_dux(char *str, t_params *arg);
/*
** ------------------------- WIDTH -------------------------
*/
char				ft_set_zero(t_params *arg);
char				*ft_malloc_width_dopux(int n, t_params *arg);
int					ft_malloc_width_s(int malloc_size, int *n, t_params *arg);
char				*ft_malloc_width_c(t_params *arg);
/*
** ------------------------- ADDITIONS FROM LIBFT -------------------------
*/
int					ft_isdigit(int c);
int					ft_eq_char(char c1, char c2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_ullonglen(unsigned long long n);
int					ft_llonglen(long long n);
int					ft_wcharlen(wchar_t c);
int					ft_wstrlen(wchar_t *wstr);
int					ft_max(size_t n, size_t p);
int					ft_abs(int n);
long long			ft_abs_ll(long long n);
char				*ft_lltoa(long long n);
char				*ft_lltoa_base(long long n, const char *base);
char				*ft_llutoa(unsigned long long n);
char				*ft_llutoa_base(unsigned long long n, const char *base);
char				*ft_strjoin_clr(char *a, char *b, int d);
void				*ft_memset(void *b, int c, size_t n);
void				*ft_bzero(void *b, size_t n);
char				*ft_strnew(size_t size);
#endif
