/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/11/29 09:15:40 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

#define ULLONG_MAX 255

int		main(int argc, char **argv)
{
	int		i1;
	int		i2;

	i1 = printf("%15.4d\n", -42);
	i2 = ft_printf("%15.4d\n", -42);
	printf("Printf = %d\nFt_Printf = %d\n", i1, i2);
	return (0);
}
