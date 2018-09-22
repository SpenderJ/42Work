/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:07:44 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/18 18:31:56 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_st(t_env *env, t_process *process)
{
	char	reg_value[4];
	char	tmp[2];
	t_param param;

	if (process->ocp[0] != 1 || ((process->ocp[1]) != 1
		&& process->ocp[1] != 3))
		return (0);
	param.value[0] = (int)env->arena[check_adress(process->current + 2)];
	if (!copy_register(process, reg_value, param.value[0])
		|| !params_size_ocp(env, process, &param))
		return (0);
	copy_memory_area(env, tmp, check_adress(process->current + 2),
		param.size[1]);
	param.value[1] = (param.size[1] == 2) ? (tmp[0] << 8
		| (unsigned char)tmp[1]) : tmp[0];
	param.adress = check_adress(param.value[1] % IDX_MOD + process->current);
	param.length = 4;
	if (param.size[1] == 2)
		modify_memory_content(env, reg_value, &param, process);
	else
		modify_register_content(process, reg_value, (int)param.value[1]);
	if (env->option.v == 4 || env->option.v < 0)
		show_operations(env, process, &param);
	return (1);
}
