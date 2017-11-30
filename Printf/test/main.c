/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:47:34 by juspende          #+#    #+#             */
/*   Updated: 2017/11/30 22:18:11 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		i2;
	int		i1;

	i2 = printf("Ur Printf:(%#.3o\n", 1);
	i1 = ft_printf("My Printf:(%#.3o\n", 1);
	printf("Printf = %d, Ft_printf = %d\n", i2, i1);
	return (0);
}
