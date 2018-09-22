/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jebossue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 18:18:31 by jebossue          #+#    #+#             */
/*   Updated: 2018/07/25 16:49:38 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	exec_sub(t_env *env, t_process *process)
{
	t_param	param;

	param.value[0] = (int)env->arena[check_adress(process->current + 2)];
	param.value[1] = (int)env->arena[check_adress(process->current + 3)];
	param.value[2] = (int)env->arena[check_adress(process->current + 4)];
	if (process->ocp[0] != 1 || process->ocp[1] != 1 || process->ocp[2] != 1)
		return (0);
	if ((param.value[0] < 1 || param.value[0] > REG_NUMBER) ||
			(param.value[1] < 1 || param.value[1] > REG_NUMBER) ||
			(param.value[2] < 1 || param.value[2] > REG_NUMBER))
		return (0);
	process->reg[param.value[2] - 1] = process->reg[param.value[0] - 1] -
		process->reg[param.value[1] - 1];
	if (process->reg[param.value[2] - 1] == 0)
		process->carry = 1;
	else
		process->carry = 0;
	if (env->option.v == 4 || env->option.v < 0)
		show_operations(env, process, &param);
	return (1);
}
