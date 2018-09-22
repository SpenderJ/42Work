/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 10:03:45 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/18 18:25:03 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		copy_register(t_process *process, char *buf, int reg_number)
{
	int i;

	i = 0;
	if (reg_number < 1 || reg_number > REG_NUMBER)
		return (0);
	while (i < 4)
	{
		buf[i] = process->reg[reg_number - 1] >> (24 - (8 * i));
		i++;
	}
	return (1);
}

void	copy_memory_area(t_env *env, char *buf, int start, int size)
{
	int i;
	int pos;

	i = 0;
	pos = start;
	while (i < size)
	{
		pos = check_adress(pos + 1);
		buf[i] = env->arena[pos];
		i++;
	}
}

void	modify_register_content(t_process *process, char *new_value,
		int reg_number)
{
	int result;

	if (reg_number < 1 || reg_number > REG_NUMBER)
		return ;
	result = new_value[0] << 24 | (unsigned char)new_value[1] << 16
		| (unsigned char)new_value[2] << 8 | (unsigned char)new_value[3];
	process->reg[reg_number - 1] = result;
}

void	modify_memory_content(t_env *env, char *buf, t_param *param,
		t_process *process)
{
	int i;
	int pos;

	i = 0;
	pos = param->adress - 1;
	while (i < param->length)
	{
		pos = check_adress(pos + 1);
		env->arena[pos] = buf[i];
		env->arena2[pos] = env->arena2[pos] % COLOR + UNDER_LINE;
		if (pos != process->current)
		{
			env->arena2[pos] -= env->arena2[pos] % COLOR;
			env->arena2[pos] += env->arena2[process->current] % COLOR;
		}
		if (env->option.visu)
			display_ncurses(env, process, pos, 0);
		i++;
	}
}
