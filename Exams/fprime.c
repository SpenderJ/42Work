/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:30:40 by juspende          #+#    #+#             */
/*   Updated: 2019/03/20 15:31:19 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			main(int argc, char **argv) {
	int		mult = 2;
	int		tot = 1;
	int		res = atoi(argv[1]);
	int		cpy = res;

	while (tot < res && argc == 2 && res > 1) {
		if (cpy % mult != 0)
			++mult;
		else {
			cpy = cpy / mult;
			tot == 1 ? printf("%d", mult) : printf("*%d", mult);
			tot = tot * mult; } }
	return (printf("\n"));
}
