/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/11/27 16:23:29 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i;
	char	*ntm;
	double	test;

	i = 42;
	test = 9999.987614321;
	ntm = strdup("Yo mon bro");
//	printf("%.7e, %d\n", test, i);
	printf("%jd\n", -9223372036854775807);
	ft_printf("%jd", -9223372036854775807);
	return (0);
}
