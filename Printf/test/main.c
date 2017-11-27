/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/11/27 11:45:11 by juspende         ###   ########.fr       */
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
	printf("%o\n", 41);
	ft_printf("%o", 41);
	return (0);
}
