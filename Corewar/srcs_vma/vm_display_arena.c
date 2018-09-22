/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_display_arena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 09:17:47 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/20 14:30:32 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		display_memory_area(char byte)
{
	if (byte == '\0')
		ft_printf("00 ");
	else
		ft_printf("%02x ", (unsigned char)byte);
	return (1);
}

int		display_specific_area(t_env *env, int start, int size)
{
	int i;

	i = start;
	while (size > 0)
	{
		i = check_adress(i);
		display_memory_area(env->arena[i]);
		size--;
		i++;
	}
	return (1);
}

int		display_arena(t_env *env)
{
	int i;
	int line;

	i = 0;
	line = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i > 1)
		{
			line++;
			ft_printf("%#06x : ", i);
		}
		display_memory_area(env->arena[i]);
		if ((i + 1) % 64 == 0)
			ft_printf("\n");
		i++;
	}
	return (1);
}
