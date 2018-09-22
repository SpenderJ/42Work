/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_exec_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:22:41 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/20 14:29:22 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		exec_options(t_env *env, int cycle)
{
	char c;

	c = '0';
	if (cycle && (env->option.d != -1)
		&& (env->option.d == env->cycle - 1) && env->process.nb_process)
	{
		display_arena(env);
		if (env->process.nb_process == 0)
			display_end(env);
		destroy_all(env, 1);
		endwin();
		exit(1);
	}
	if (env->cycle != 1 && env->option.s
		&& ((env->cycle - 1) % env->option.s == 0))
	{
		display_arena(env);
		while (c != '\n')
			if (read(0, &c, 1) == -1)
				exit(1);
	}
	if (cycle == 1 && (env->option.v == 2 || env->option.v < 0)
		&& env->process.nb_process)
		ft_printf("It is now cycle %d\n", env->cycle);
	return (1);
}

int		exec_process(t_env *env)
{
	t_process *process;

	process = env->process.first_process;
	while (process)
	{
		if (process->cycle_before_exec == 0)
			new_instruction(env, process);
		if (process->cycle_before_exec == 1)
			exec_instruction(env, process);
		process->cycle_before_exec--;
		process = process->next;
	}
	if (env->process.first_process && env->option.visu)
		ft_display(env);
	return (1);
}

void	run_the_game(t_env *env, int cycle_consumed, int check, int delta)
{
	display_start(env);
	exec_options(env, 0);
	while (env->process.nb_process && (env->option.d == -1
		|| env->option.d >= env->cycle - 1))
	{
		if (cycle_consumed >= env->cycle_to_die)
		{
			check++;
			search_dead_process(env);
			cycle_consumed = 0;
			if (env->nb_live_env >= NBR_LIVE || check == MAX_CHECKS)
			{
				check = 0;
				delta = 1;
				env->cycle_to_die -= CYCLE_DELTA;
			}
			env->nb_live_env = 0;
		}
		if (delta && (env->option.v == 2 || env->option.v < 0) && !(delta = 0))
			ft_printf("Cycle to die is now %d\n", env->cycle_to_die);
		exec_options(env, 1);
		exec_process(env);
		env->cycle++;
		cycle_consumed++;
	}
}
