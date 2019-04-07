/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 11:00:34 by juspende          #+#    #+#             */
/*   Updated: 2019/04/07 14:54:37 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_ssl.h"
# include "../includes/ft_md5.h"

void		output(uint8_t *hash, t_ssl *ssl, t_ssl_flag *ssl_flag, int index)
{
	int		z;
	int		code;

	z = -1;
	if (ssl->md5)
		code = MD5;
	if (ssl->sha256)
		code = SHA256;
	if (ssl->sha512)
		code = SHA512;
	if (ssl->whirpool)
		code = WHIRPOOL;
	if (ssl->to_hash[index] && ssl_flag->p && index == 0 && ssl->c_stdin)
		printf("%s\n", ssl->to_hash[index]);
	if (ssl->c_stdin && ssl->to_hash[index] && index == 0)
		while (++z < 16)
			printf("%2.2x", hash[z]);
	else if (ssl->to_hash[index])
	{
		if (!ssl_flag->q && !ssl_flag->r)
		{
			code == MD5 ? ft_printf("MD5 (%s) = ",
					ssl->filenames[index - ssl->c_stdin]) : 0;
			code == SHA256 ? ft_printf("SHA256 (%s) = ",
					ssl->filenames[index - ssl->c_stdin]) : 0;
			code == SHA512 ? ft_printf("SHA512 (%s) = ",
					ssl->filenames[index - ssl->c_stdin]) : 0;
			code == WHIRPOOL ? ft_printf("WHIRPOOL (%s) = ",
					ssl->filenames[index - ssl->c_stdin]) : 0;
		}
		while (++z < 16)
			printf("%2.2x", hash[z]);
		if (ssl_flag->r)
			printf(" %s", ssl->filenames[index - ssl->c_stdin]);
	}
	else
	{
		code == MD5 ? printf("ft_ssl: %s: %s: No such file or directory",
				"md5", ssl->filenames[index - ssl->c_stdin]) : 0;
		code == SHA256 ? printf("ft_ssl: %s: %s: No such file or directory",
				"sha256", ssl->filenames[index - ssl->c_stdin]) : 0;
		code == SHA512 ? printf("ft_ssl: %s: %s: No such file or directory",
				"sha512", ssl->filenames[index - ssl->c_stdin]) : 0;
		code == WHIRPOOL ? printf("ft_ssl: %s: %s: No such file or directory",
				"whirpool", ssl->filenames[index - ssl->c_stdin]) : 0;
	}
	printf("\n");
}
