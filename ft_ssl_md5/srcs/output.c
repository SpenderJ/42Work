/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:00:34 by juspende          #+#    #+#             */
/*   Updated: 2019/04/08 13:37:33 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ssl.h"
# include "../includes/ft_md5.h"

static int	ft_digits(int n, int base)
{
	int		i;

	i = 1;
	while (n /= base)
		++i;
	return (i);
}

static char	*itoa_base(int n, int base)
{
	int			i;
	int			mod;
	char		*str;
	static char	digits[31] = "0123456789abcdefghijklmnopqrst";

	if (base > 30)
		return (NULL);
	i = ft_digits(n, base);
	mod = n < 0;
	if (!(str = malloc((i + 1 + mod) * sizeof(char))))
		return (NULL);
	if (mod)
		*str++ = '-';
	str += i - 1;
	*(str + 1) = '\0';
	if (n == 0)
		*str-- = '0';
	while (n)
	{
		*str-- = digits[(n % base) * (mod ? -1 : 1)];
		n /= base;
	}
	return (str + 1 - mod);
}

static void	p_error(int code, t_ssl *ssl, int index)
{
	code == MD5 ? ft_printf("ft_ssl: %s: %s: No such file or directory",
				"md5", ssl->filenames[index - ssl->c_stdin]) : 0;
		code == SHA256 ? ft_printf("ft_ssl: %s: %s: No such file or directory",
				"sha256", ssl->filenames[index - ssl->c_stdin]) : 0;
		code == SHA512 ? ft_printf("ft_ssl: %s: %s: No such file or directory",
				"sha512", ssl->filenames[index - ssl->c_stdin]) : 0;
		code == WHIRPOOL ? ft_printf("ft_ssl: %s: %s: No such file or directory",
				"whirpool", ssl->filenames[index - ssl->c_stdin]) : 0;
}

static void	p_success(t_ssl *ssl, t_ssl_flag *ssl_flag, int index, int code)
{
	if (!ssl_flag->s || index != 0 + ssl->c_stdin)
	{
		code == MD5 ? ft_printf("MD5(%s)= ",
				ssl->filenames[index - ssl->c_stdin]) : 0;
		code == SHA256 ? ft_printf("SHA256(%s)= ",
				ssl->filenames[index - ssl->c_stdin]) : 0;
		code == SHA512 ? ft_printf("SHA512(%s)= ",
				ssl->filenames[index - ssl->c_stdin]) : 0;
		code == WHIRPOOL ? ft_printf("WHIRPOOL(%s)= ",
				ssl->filenames[index - ssl->c_stdin]) : 0;
	}
	else
	{
		code == MD5 ? ft_printf("MD5(\"%s\")= ",
				ssl->filenames[index - ssl->c_stdin]) : 0;
		code == SHA256 ? ft_printf("SHA256(\"%s\")= ",
				ssl->filenames[index - ssl->c_stdin]) : 0;
		code == SHA512 ? ft_printf("SHA512(\"%s\")= ",
				ssl->filenames[index - ssl->c_stdin]) : 0;
		code == WHIRPOOL ? ft_printf("WHIRPOOL(\"%s\")= ",
				ssl->filenames[index - ssl->c_stdin]) : 0;
	}
}

void		output(uint8_t *hash, t_ssl *ssl, t_ssl_flag *ssl_flag, int index)
{
	int		z;
	int		code;

	z = -1;
	(void)itoa_base;
	ssl->md5 ? code = MD5 : 0;
	ssl->sha256 ? code = SHA256 : 0;
	ssl->sha512 ? code = SHA512 : 0;
	ssl->whirpool ? code = WHIRPOOL : 0;
	if (ssl->to_hash[index] && ssl_flag->p && index == 0 && ssl->c_stdin)
		ft_printf("%s\n", ssl->to_hash[index]);
	if (ssl->c_stdin && ssl->to_hash[index] && index == 0)
		while (++z < 16)
			ft_printf("%2.2x", hash[z]);
	else if (ssl->to_hash[index])
	{
		if (!ssl_flag->q && !ssl_flag->r)
			p_success(ssl, ssl_flag, index, code);
		while (++z < 16)
			ft_printf("%2.2x", hash[z]);
		if (ssl_flag->r && ssl_flag->s && index == 0 + ssl->c_stdin && !ssl_flag->q)
			ft_printf(" \"%s\"", ssl->filenames[index - ssl->c_stdin]);
		else if (ssl_flag->r && !ssl_flag->q)
			ft_printf(" %s", ssl->filenames[index - ssl->c_stdin]);
	}
	else
		p_error(code, ssl, index);
	ft_printf("\n");
}