/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_instructions_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:48:18 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/22 17:57:01 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		params_size_ocp(t_env *env, t_process *process, t_param *param)
{
	int	op;
	int	i;

	i = 0;
	if ((op = (int)process->opcode) < 1
			|| (int)process->opcode > NB_INSTRUCTIONS)
		return (0);
	param->size[0] = process->ocp[0];
	param->size[1] = process->ocp[1];
	param->size[2] = process->ocp[2];
	while (i < 3)
	{
		if (param->size[i] == 2 && env->instructions[op - 1].direct_size == 0)
			param->size[i] += 2;
		if (param->size[i] == 3)
			param->size[i] -= 1;
		i++;
	}
	return (1);
}

int		size_param(t_env *env, t_process *process)
{
	int i;
	int instruction;
	int result;

	i = 0;
	result = 2;
	instruction = (int)(process->opcode) - 1;
	if (instruction < 0 || instruction >= NB_INSTRUCTIONS)
		return (result);
	while (i < 3 && i < env->instructions[instruction].params_number)
	{
		if (process->ocp[i] == 1)
			result++;
		else if (process->ocp[i] == 3)
			result = result + 2;
		else if (process->ocp[i] == 2)
			result += (env->instructions[instruction].direct_size == 1) ? 2 : 4;
		i++;
	}
	return (result);
}

int		check_ocp(t_env *env, t_process *process)
{
	int		ocp;
	int		result;
	int		i;

	i = 1;
	ocp = (unsigned int)env->arena[check_adress(process->current + i)] / 4;
	process->ocp[2] = ocp % 4;
	ocp = ocp / 4;
	process->ocp[1] = ocp % 4;
	ocp = ocp / 4;
	process->ocp[0] = ocp % 4;
	result = size_param(env, process);
	return (result);
}

int		size_instruction(t_env *env, t_process *process)
{
	int opcode;

	opcode = (int)process->opcode;
	if (opcode < 1 || opcode > (int)NB_INSTRUCTIONS)
		return (1);
	else if (opcode == 9 || opcode == 12 || opcode == 15)
		return (3);
	else if (opcode == 1)
		return (5);
	else
		return (check_ocp(env, process));
}
