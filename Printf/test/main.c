/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 18:22:09 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

#define ULLONG_MAX 255

int		main(int argc, char **argv)
{
	int		i1;
	int		i2;
	char	c;
	long long ll = 9223372036854775807;

	c = '0';
	i1 = printf("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
	i2 = ft_printf("%x %X %20.15d\n", 505, 505, 54321);
	printf("Printf = %d\nFt_Printf = %d\n", i1, i2);
	return (0);
}
