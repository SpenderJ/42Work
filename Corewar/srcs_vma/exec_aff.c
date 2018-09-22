/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 09:09:08 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/18 18:11:08 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_aff(t_env *env, t_process *process)
{
	char	reg_value[4];
	int		value;

	if (!env->option.a)
		return (0);
	if (!copy_register(process, reg_value,
				(int)env->arena[check_adress(process->current + 2)]))
		return (0);
	if (process->ocp[0] != 1)
		return (0);
	value = reg_value[0] << 24 | reg_value[1] << 16 | reg_value[2] << 8
		| reg_value[3];
	value = value % 256;
	ft_printf("Aff : %c\n", value);
	return (0);
}
