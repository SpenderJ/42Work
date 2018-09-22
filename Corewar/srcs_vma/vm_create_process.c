/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_create_process.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 09:47:39 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/20 11:24:19 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	init_new(t_env *env, t_process *new, int start_position, t_fork *fork)
{
	new->id = env->process.process_id;
	new->current = start_position;
	new->pc = (fork) ? fork->pc : start_position;
	new->opcode = env->arena[start_position];
	new->cycle_before_exec = 0;
	new->col_pair = (fork) ? fork->col_pair : -1 * new->reg[0];
	new->carry = (fork) ? fork->carry : 0;
	new->alive = (fork) ? fork->alive : 0;
	new->last = (fork) ? fork->last : 0;
	new->prev = NULL;
	new->next = env->process.first_process;
}

void	create_process(t_env *env, int *reg, int start_position, t_fork *fork)
{
	t_process	*new;
	int			i;

	if (!(new = (t_process *)malloc(sizeof(t_process))))
		display_errors("Error : process memory not allocated.");
	i = -1;
	while (++i < REG_NUMBER)
		new->reg[i] = reg[i];
	init_new(env, new, start_position, fork);
	if (new->next != NULL)
		env->process.first_process->prev = new;
	env->process.first_process = new;
	if (fork)
		new_instruction(env, new);
	env->process.process_id++;
	env->process.nb_process++;
	if (env->option.visu)
		display_ncurses(env, new, new->pc, 0);
}

int		init_process_stack(t_env *env)
{
	int		reg[REG_NUMBER];
	int		i;
	int		j;

	i = 0;
	while (ft_strlen(env->champions[i].file))
	{
		reg[0] = -1 * env->champions[i].player_id;
		j = 1;
		while (j < REG_NUMBER)
		{
			reg[j] = 0;
			j++;
		}
		create_process(env, reg, i * MEM_SIZE / env->nb_players, 0);
		if (i == 0)
		{
			env->process.last_process = env->process.first_process;
			env->process.last_process->next = NULL;
			env->process.last_process->prev = NULL;
			env->process.followed = env->process.first_process;
		}
		i++;
	}
	return (1);
}
