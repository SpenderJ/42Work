/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_destroy_process.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:36:52 by aserguie          #+#    #+#             */
/*   Updated: 2018/08/18 18:37:30 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	free_memory(t_env *env, t_process *process, int d)
{
	if ((env->option.v == 8 || env->option.v < 0) && d == 0)
		show_deaths(env, process);
	if (env->option.visu)
	{
		env->arena2[process->current] %= UNDER_LINE;
		display_ncurses(env, process, process->current, 0);
	}
	ft_memdel((void **)&process);
	if (env->process.nb_process > 0)
		env->process.nb_process--;
}

void	destroy_all(t_env *env, int d)
{
	t_process *tmp;

	while (env->process.first_process)
	{
		tmp = env->process.first_process->next;
		free_memory(env, env->process.first_process, d);
		env->process.first_process = tmp;
	}
}

void	destroy_process(t_env *env, t_process *process)
{
	if (process == env->process.first_process)
	{
		env->process.first_process = process->next;
		if (env->process.first_process)
			env->process.first_process->prev = NULL;
		free_memory(env, process, 0);
	}
	else
	{
		(process->prev)->next = process->next;
		if (process->next != NULL)
			process->next->prev = process->prev;
		free_memory(env, process, 0);
	}
}

int		search_dead_process(t_env *env)
{
	t_process	*tmp;
	t_process	*process;
	int			destr_follow;

	destr_follow = 0;
	process = env->process.first_process;
	while (process)
		if (process->alive == 0)
		{
			if (process == env->process.followed)
				destr_follow = 1;
			tmp = process->next;
			if (tmp == NULL)
				env->process.last_process = process->prev;
			destroy_process(env, process);
			process = tmp;
		}
		else
		{
			process->alive = 0;
			process = process->next;
		}
	if (destr_follow == 1)
		env->process.followed = env->process.first_process;
	return (1);
}
