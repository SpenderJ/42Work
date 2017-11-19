/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:34:36 by juspende          #+#    #+#             */
/*   Updated: 2017/11/06 11:34:39 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int	i;
	int	a;

	a = 0;
	while (argv[++a] != NULL && argc)
	{
		i = -1;
		while (argv[a][++i] != '\0')
			ft_putchar(argv[a][i]);
		ft_putchar('\n');
	}
	return (0);
}
