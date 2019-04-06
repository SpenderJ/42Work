/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:36:08 by juspende          #+#    #+#             */
/*   Updated: 2019/04/05 19:28:06 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static int	usage(char **av)
{
	ft_printf("usage: %s [md5 | sha256 | sha512 | whirpool] [-pqrshv]"
			" [filename (%d MAX)] ...\n\n"
			"  -md5            will encrypt in md5\n"
			"  -sha256         will encrypt in sha256\n"
			"  -sha512         will encrypt in sha512\n"
			"  -whirpool       will encrypt in whirpool\n\n"
			"  -p              echo STDIN to STDOUT and append the checksum"
			"to STDOUT\n"
			"  -q              quiet mode\n"
			"  -r              reverse the format of the output\n"
			"  -s              print the sum of the given string\n"
			"  -h              show this help\n"
			"  -v              toggle colors and more detailled explanations\n"
			, av[0], MAX_FILES);
	return (EXIT_HELP);
}

static int	opt_exh(t_ssl_flag *ssl_flag, char comp)
{
	int		ret;

	ret = -1;
	if (comp == 'p' && (ssl_flag->p = TRUE) == TRUE)
		ret = 0;
	else if (comp == 'q' && (ssl_flag->q = TRUE) == TRUE)
		ret = 0;
	else if (comp == 'r' && (ssl_flag->r = TRUE) == TRUE)
		ret = 0;
	else if (comp == 's' && (ssl_flag->s = TRUE) == TRUE)
		ret = 0;
	else if (comp == 'h' && (ssl_flag->h = TRUE) == TRUE)
		ret = 0;
	else if (comp == 'v' && (ssl_flag->v = TRUE) == TRUE)
		ret = 0;
	return (ret);
}

static int	opt(t_ssl_flag *ssl_flag, t_ssl *ssl, int ac, char **av)
{
	int		opt;
	int		ret;

	opt = 0;
	ret = 0;
	if (++opt < ac)
	{
		ft_strcmp(av[opt], "md5") == 0 ? ssl->md5 = TRUE : 0;
		ft_strcmp(av[opt], "sha256") == 0 ? ssl->sha256 = TRUE : 0;
		ft_strcmp(av[opt], "sha512") == 0 ? ssl->sha512 = TRUE : 0;
		ft_strcmp(av[opt], "whirpool") == 0 ? ssl->whirpool = TRUE : 0;
		if (!ssl->md5 && !ssl->sha256 && !ssl->sha512 && !ssl->whirpool)
			return (usage(av));
	}
	while (++opt < ac && av[opt][0] == '-' &&
			(ret = opt_exh(ssl_flag, av[opt][1])) != SEG)
		if (ret == -1 || ssl_flag->h == TRUE)
			return (usage(av));
	ret = 0;
	while (opt < ac && ret < MAX_FILES)
		ssl->filenames[ret++] = ft_strdup(av[opt++]);
	ssl->filenames[ret] = NULL;
	if (ret >= MAX_FILES)
		return (usage(av));
	return (0);
}


int			main(int ac, char **av)
{
	t_ssl_flag		ssl_flag;
	t_ssl			ssl;

	ft_bzero(&ssl_flag, sizeof(t_ssl_flag));
	ft_bzero(&ssl, sizeof(t_ssl));
	if ((ssl.filenames = malloc(sizeof(char *) * MAX_FILES)) == NULL)
		return (usage(av));
	if (opt(&ssl_flag, &ssl, ac, av) == EXIT_HELP)
		return (EXIT_HELP);
	if (io(&ssl) == EXIT_HELP)
		return (EXIT_HELP);
	ssl.md5 == TRUE ? md5(&ssl, &ssl_flag) : 0;
	ssl.sha256 == TRUE ? sha256(&ssl, &ssl_flag) : 0;
	ssl.sha512 == TRUE ? sha512(&ssl, &ssl_flag) : 0;
	ssl.whirpool == TRUE ? whirpool(&ssl, &ssl_flag) : 0;
	return (0);
}
