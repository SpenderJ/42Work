/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inner_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:42:45 by juspende          #+#    #+#             */
/*   Updated: 2018/04/24 11:44:31 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			check_name_header(char *arg)
{
	char	tab[4];
	int		i;

	i = 0;
	// tab[0] = (char)0xffffffbe;
	tab[0] = 0;
	tab[1] = (char)0xffffffea;
	tab[2] = (char)0xffffff83;
	tab[3] = (char)0xfffffff3;
	if (ft_b_strncmp(tab, arg, 4))
		return (0);
	return (1);
}

char		*inner_parser(char *arg, int len)
{
	int		i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		str[i] = arg[i];
		++i;
		// if (arg[i] == 0)
		// break ;
	}
	str[i] = '\0';
	// print_arg(arg, len, 'h');
	return (str);
}
