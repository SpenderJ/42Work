/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:45:43 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/18 18:38:27 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		display_process(t_env *env)
{
	int			i;
	t_process	*process;

	process = env->process.first_process;
	while (process)
	{
		i = -1;
		ft_printf("PROCESS\nregistres : ");
		while (i++ < REG_NUMBER - 1)
			ft_printf("%d ", process->reg[i]);
		ft_printf("\ncurrent : %d\npc : %d\nopcode : %d\ncycle_before_exec :"
			" %d\nalive : %d\n\n", process->current, process->pc,
			process->opcode, process->cycle_before_exec, process->alive);
		process = process->next;
	}
	return (1);
}

int		display_champions(t_env *env)
{
	int i;

	i = 0;
	while (env->champions[i].header.magic != 0)
	{
		ft_printf("Player : %d\nHeader => magic : %d, prog_name : %s, size :"
			" %d, comment : %s\n", env->champions[i].player_id,
			env->champions[i].header.magic, env->champions[i].header.prog_name,
			env->champions[i].header.prog_size,
			env->champions[i].header.comment);
		i++;
	}
	return (1);
}

int		display_instructions(t_env *env)
{
	int i;
	int j;

	i = 0;
	while (i < 16)
	{
		j = -1;
		ft_printf("name : \"%s\", number : %d params :",
				env->instructions[i].name, env->instructions[i].params_number);
		while (j++ < 2)
			ft_printf(" %d", env->instructions[i].params[j]);
		ft_printf(" opcode : %x, nb_cycles : %d, description \"%s\", mod_carry "
			"%d, direct_size %d.\n", env->instructions[i].op_code,
			env->instructions[i].nb_cycles, env->instructions[i].description,
			env->instructions[i].modify_carry,
			env->instructions[i].direct_size);
		i++;
	}
	return (1);
}

int		debug(t_env *env)
{
	if (!env)
		return (0);
	display_arena(env);
	return (1);
}
