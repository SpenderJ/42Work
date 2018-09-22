/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_xor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 17:24:38 by jebossue          #+#    #+#             */
/*   Updated: 2018/08/20 12:48:28 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	xor_param2(t_env *env, t_process *process, t_param *param, int i)
{
	char	tmp[4];
	int		head;
	int		head2param;

	head = (i == 1) ? (process->current + 1 + param->size[0]) :
		(process->current + 1);
	copy_memory_area(env, tmp, check_adress(head), param->size[i]);
	if (param->size[i] == 4)
	{
		copy_memory_area(env, param->param[i], head, 4);
		param->value[i] = tmp[0] << 24 | (unsigned char)tmp[1] << 16
			| (unsigned char)tmp[2] << 8 | (unsigned char)tmp[3];
	}
	else if (param->size[i] == 2)
	{
		head2param = tmp[0] << 8 | (unsigned char)tmp[1];
		copy_memory_area(env, param->param[i], head2param % IDX_MOD
				+ process->current - 1, 4);
		param->value[i] = indirect_value(env, head2param % IDX_MOD
				+ process->current);
	}
	return (1);
}

int	xor_param(t_env *env, t_process *process, t_param *param, int i)
{
	char	tmp[4];
	int		head;
	int		j;

	j = 0;
	if (i == 1)
		head = process->current + 1 + param->size[0];
	else
		head = process->current + 1;
	copy_memory_area(env, tmp, check_adress(head), param->size[i]);
	if (process->ocp[i] == 1 && ((int)tmp[0] < 1 || (int)tmp[0] > REG_NUMBER))
		return (0);
	if (param->size[i] == 1)
	{
		copy_register(process, param->param[i], (int)tmp[0]);
		param->value[i] = register_value(process, (int)tmp[0]);
	}
	return (xor_param2(env, process, param, i));
}

int	check_xor(t_env *env, t_process *process, t_param *param)
{
	if ((process->ocp[0] != 1 && process->ocp[0] != 2 && process->ocp[0] != 3)
		|| (process->ocp[1] != 1 && process->ocp[1] != 2
			&& process->ocp[1] != 3) || process->ocp[2] != 1)
		return (0);
	if (!params_size_ocp(env, process, param))
		return (0);
	param->value[2] = (int)env->arena[check_adress(process->current + 2
			+ param->size[0] + param->size[1])];
	if (param->value[2] < 1 || param->value[2] > NB_INSTRUCTIONS)
		return (0);
	return (1);
}

int	exec_xor(t_env *env, t_process *process)
{
	t_param	param;
	int		i;
	char	result[4];
	int		intresult;

	i = 0;
	if (!check_xor(env, process, &param))
		return (0);
	if (!xor_param(env, process, &param, 0))
		return (0);
	if (!xor_param(env, process, &param, 1))
		return (0);
	while (i < 4)
	{
		result[i] = param.param[0][i] ^ param.param[1][i];
		i++;
	}
	modify_register_content(process, result, param.value[2]);
	intresult = result[0] << 24 | result[1] << 16 | result[2] << 8 | result[3];
	process->carry = (intresult == 0) ? 1 : 0;
	if (env->option.v == 4 || env->option.v < 0)
		show_operations(env, process, &param);
	return (1);
}
