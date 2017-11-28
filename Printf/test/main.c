/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/11/28 13:52:14 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

#define UCHAR_MAX 255

int		main(int argc, char **argv)
{
	int		i1;
	int		i2;

	i1 = printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
	i2 = ft_printf("%hhu, %hhu\n", 0, UCHAR_MAX + 42);
	printf("Printf = %d\nFt_Printf = %d\n", i1, i2);
	return (0);
}
