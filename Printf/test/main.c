/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/12/06 09:26:13 by juspende         ###   ########.fr       */
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
	int		tmp1;
	int		tmp2;

	setlocale(LC_ALL, "");
//	return (0);
//	i2 = printf("LE VRAI Printf:{%f}%n{%F}\n", -1.42, &tmp1, -1.42);
	ft_printf("%b5 LE MIEN Printf%b0:{%f}%n%b4{%F}\n", -1.42, &tmp2, -1.42);
//printf("VRAI_printf = %d %d\nMy_printf = %d %d\n", i2, tmp1, i1, tmp2);
	return (0);
}
