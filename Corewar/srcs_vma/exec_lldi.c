/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lldi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 17:44:42 by aserguie          #+#    #+#             */
/*   Updated: 2018/08/18 18:32:33 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_lldi(t_env *env, t_process *process, t_param *param)
{
	if ((process->ocp[0] != 1 && process->ocp[0] != 2 && process->ocp[0] != 3)
			|| (process->ocp[1] != 1 && process->ocp[1] != 2)
			|| process->ocp[2] != 1)
		return (0);
	if (!params_size_ocp(env, process, param))
		return (0);
	param->value[2] = (int)env->arena[check_adress(process->current + 2
			+ param->size[0] + param->size[1])];
	if (param->value[2] < 1 || param->value[2] > (int)REG_NUMBER)
		return (0);
	return (1);
}

void	ft_do_lldi(t_env *env, t_process *process, t_param param, char *tmp)
{
	param.adress = process->current + (param.value[0] + param.value[1]);
	copy_memory_area(env, tmp, check_adress(param.adress - 1), 4);
	modify_register_content(process, tmp, param.value[2]);
	process->carry = (process->reg[param.value[2] - 1] == 0) ? 1 : 0;
	if (env->option.v == 4 || env->option.v < 0)
		show_operations(env, process, &param);
}

int		exec_lldi(t_env *env, t_process *process)
{
	t_param	param;
	char	tmp[4];
	int		i;

	i = -1;
	if (!check_lldi(env, process, &param))
		return (0);
	while (++i < 2)
	{
		copy_memory_area(env, (tmp + 2 * i), check_adress(process->current + 1
					+ i * param.size[0]), param.size[i]);
		if (((int)tmp[2 * i] < 1 || (int)tmp[2 * i] > (int)REG_NUMBER)
				&& param.size[i] == 1)
			return (0);
		else if (param.size[i] == 1)
			param.value[i] = register_value(process, (int)tmp[2 * i]);
		else if (process->ocp[i] == 2)
			param.value[i] = (tmp[2 * i] << 8 | (unsigned char)tmp[2 * i + 1]);
		else if (i == 0)
			param.value[0] = indirect_value(env, check_adress(process->current
						+ (tmp[0] << 8 | (unsigned char)tmp[1]) % IDX_MOD));
	}
	ft_do_lldi(env, process, param, tmp);
	return (1);
}
