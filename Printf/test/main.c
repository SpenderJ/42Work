/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 07:23:55 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <limits.h>

int		main(int argc, char **argv)
{
	int		i2;
	int		i1;

	setlocale(LC_ALL, "");
	i2 = printf("LE VRAI Printf:{%f}{%F}\n", -1.42, -1.42);
	i1 = ft_printf("LE MIEN Printf:{%f}{%F}\n", -1.42, -1.42);
	printf("VRAI_printf = %d\nMy_printf = %d\n", i2, i1);
	return (0);
}
