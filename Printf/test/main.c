/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 13:36:19 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

#define LONG_MAX 4294967295

int		main(int argc, char **argv)
{
	int		i1;
	int		i2;

	i1 = printf("%D\n", LONG_MAX);
	i2 = ft_printf("%D\n", LONG_MAX);
	printf("Printf = %d\nFt_Printf = %d\n", i1, i2);
	return (0);
}
