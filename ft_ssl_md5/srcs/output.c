/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:00:34 by juspende          #+#    #+#             */
/*   Updated: 2019/04/13 16:39:42 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"
#include "../includes/ft_md5.h"

static uint32_t	swap_int32(const uint32_t value)
{
	uint32_t result;

	result = 0;
	result |= (value & 0x000000FF) << 24;
	result |= (value & 0x0000FF00) << 8;
	result |= (value & 0x00FF0000) >> 8;
	result |= (value & 0xFF000000) >> 24;
	return (result);
}

static void		print_md5(uint32_t *digest)
{
	int			i;
	uint32_t	tmp;

	i = -1;
	while (++i < 16 / 4)
	{
		tmp = digest[i];
		tmp = swap_int32(tmp);
		printf("%8.8x", tmp);
	}
}

static void		p_error(int code, t_ssl *ssl, int index)
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

static void		p_success(t_ssl *ssl, t_ssl_flag *ssl_flag, int index, int code)
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

void			output(uint32_t *hash, t_ssl *ssl, t_ssl_flag *ssl_flag, int i)
{
	int		z;
	int		code;

	z = -1;
	ssl->md5 ? code = MD5 : 0;
	ssl->sha256 ? code = SHA256 : 0;
	ssl->sha512 ? code = SHA512 : 0;
	ssl->whirpool ? code = WHIRPOOL : 0;
	if (ssl->to_hash[i] && ssl_flag->p && i == 0 && ssl->c_stdin)
		ft_printf("%s\n", ssl->to_hash[i]);
	if (ssl->c_stdin && ssl->to_hash[i] && i == 0)
		print_md5(hash);
	else if (ssl->to_hash[i])
	{
		!ssl_flag->q && !ssl_flag->r ? p_success(ssl, ssl_flag, i, code) : 0;
		print_md5(hash);
		if (ssl_flag->r && ssl_flag->s && i == 0 + ssl->c_stdin && !ssl_flag->q)
			ft_printf(" \"%s\"", ssl->filenames[i - ssl->c_stdin]);
		else if (ssl_flag->r && !ssl_flag->q)
			ft_printf(" %s", ssl->filenames[i - ssl->c_stdin]);
	}
	!ssl->to_hash[i] ? p_error(code, ssl, i) : 0;
	ft_printf("\n");
}
