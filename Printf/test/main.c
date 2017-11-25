/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/11/25 16:39:48 by juspende         ###   ########.fr       */
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
	printf("%x\n", 42);
	ft_printf("%x\n", 42);
	return (0);
}
