/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_visu_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:48:04 by aserguie          #+#    #+#             */
/*   Updated: 2018/08/21 18:29:33 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_print_info(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	mvprintw(0, 0, "Press SPACE to pause, Q to quit, LEFT/RIGHT to navigate "
			"between processes and UP/DOWN to change speed");
	while (++i < env->nb_players)
	{
		attron(COLOR_PAIR(i + 1));
		j = -1;
		while (++j < 21 && env->champions[i].header.prog_name[j]
		&& env->champions[i].header.prog_name[j] != '\n')
			mvprintw(30 + i, 200 + j, "%c",
			env->champions[i].header.prog_name[j]);
		attron(COLOR_PAIR(i + 1));
	}
}

void	ft_display_pcs(t_env *env)
{
	t_process *process;

	process = env->process.first_process;
	while (process)
	{
		env->arena2[process->current] += env->arena2[process->current]
			< STAND_OUT ? STAND_OUT : 0;
		display_ncurses(env, process, process->current, 1);
		process = process->next;
	}
	display_ncurses(env, env->process.followed,
			env->process.followed->current, 5);
}

void	ft_display_followed(t_env *env, int *c)
{
	t_process	*pc_tmp;

	while (!(*c == ' '))
	{
		pc_tmp = env->process.followed;
		if (*c == KEY_LEFT)
			env->process.followed = (env->process.followed->next == NULL) ?
				env->process.first_process : env->process.followed->next;
		else if (*c == KEY_RIGHT)
			env->process.followed = (env->process.followed->prev == NULL) ?
				env->process.last_process : env->process.followed->prev;
		else if (*c == KEY_UP)
			env->cycle_sec += env->cycle_sec < 9990 ? 10 : 0;
		else if (*c == KEY_DOWN)
			env->cycle_sec -= env->cycle_sec > 10 ? 10 : 0;
		display_info_ncurses(env, env->process.followed);
		display_ncurses(env, pc_tmp, pc_tmp->current, 1);
		display_ncurses(env, env->process.followed,
			env->process.followed->current, 5);
		*c = getch();
		refresh();
	}
}

void	ft_pause(t_env *env)
{
	int c;
	int pause;

	pause = 0;
	while ((((c = getch()) == ' ' || c == 'q') && pause == 0) || c == KEY_LEFT
			|| c == KEY_RIGHT || c == KEY_UP || c == KEY_DOWN)
	{
		nodelay(stdscr, FALSE);
		if (c == ' ')
			c = getch();
		if (c == KEY_LEFT || c == KEY_RIGHT || c == KEY_UP || c == KEY_DOWN)
			ft_display_followed(env, &c);
		if (c == ' ' || c == 'q')
		{
			if (c == 'q')
			{
				endwin();
				destroy_all(env, 1);
				exit(1);
			}
			pause = 1;
			nodelay(stdscr, TRUE);
		}
		refresh();
	}
}

void	ft_display(t_env *env)
{
	mvprintw(25, 200, "CYCLE =  %d", env->cycle - 1);
	mvprintw(27, 200, "PROCESSES = %d", env->process.nb_process);
	ft_display_pcs(env);
	refresh();
	ft_pause(env);
	timeout(1000 / env->cycle_sec);
}
