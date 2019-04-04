/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:36:08 by juspende          #+#    #+#             */
/*   Updated: 2019/04/03 20:33:29 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static int	usage(char **av)
{
	ft_printf("usage: %s [md5 | sha256 | sha512 | whirpool] [-pqrshvi] [filename | text]\n", av[0], av[0]);
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
	else if (comp == 'i' && (ssl_flag->i = TRUE) == TRUE)
		ret = 0;
	return (ret);
}

static int	opt(t_ssl_flag *ssl_flag, t_ssl *ssl, int ac, char **av)
{
	int		opt;
	int		ret;

	opt = 0;
	ret = 0;
	(void)ssl;
	while (++opt < ac)
	{
		if (av[opt][0] == '-')
			ret = opt_exh(ssl_flag, av[opt][1]);
		if (ret == -1 || ssl_flag->h == TRUE)
			return (usage(av));
	}
	return (0);
}


int			main(int ac, char **av)
{
	t_ssl_flag		ssl_flag;
	t_ssl			ssl;

	(void)ac;
	(void)av;
	ft_bzero(&ssl_flag, sizeof(t_ssl_flag));
	ft_bzero(&ssl, sizeof(t_ssl));
	if (opt(&ssl_flag, &ssl, ac, av) == EXIT_HELP)
		return (EXIT_HELP);
	return (0);
}
