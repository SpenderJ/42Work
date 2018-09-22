/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_display_messages.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 09:45:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/20 17:24:42 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_usage(char **argv)
{
	ft_printf("Usage: %s [-a -d N -s N -v N | -visu] [-n N] <champion1.cor> "
			"[-n N] <champion2.cor> <...>\n"
	"\t-a        : Prints output from \"aff\" (Default is to hide it)\n"
	"#### TEXT OUTPUT MODE #################################################\n"
	"\t-d N      : Dumps memory after N cycles then exits\n"
	"\t-s N      : Runs N cycles, dumps memory, pauses, then repeats\n"
	"\t-v N      : Verbosity levels\n"
	"\t\t- -1 : Show everything\n"
	"\t\t- 0  : Show only essentials\n"
	"\t\t- 1  : Show lives\n"
	"\t\t- 2  : Show cycles\n"
	"\t\t- 4  : Show operations (Params are NOT litteral ...)\n"
	"\t\t- 8  : Show deaths\n"
	"\t\t- 16 : Show PC movements (Except for jumps)\n"
	"#### CHANGE PLAYER ORDER ##############################################\n"
	"\t-n N      : Attributes Nth place to following champion  if available.\n"
	"#### NCURSES OUTPUT MODE ##############################################\n"
	"\t-visu     : Ncurses output mode\n"
	"#######################################################################\n",
	argv[0]);
	exit(0);
}

int		display_end(t_env *env)
{
	if (!env->option.visu)
		ft_printf("Contestant %d, \"%s\", has won !\n",
			env->last_alive->player_id, env->last_alive->header.prog_name);
	else
	{
		attron(COLOR_PAIR(env->last_alive->player_id));
		mvprintw(35, 195, "Contestant %d, \"%s\", has won !\n",
				env->last_alive->player_id, env->last_alive->header.prog_name);
		attroff(COLOR_PAIR(env->last_alive->player_id));
		mvprintw(0, 0, "Press any key to quit the game.\n",
				env->last_alive->player_id, env->last_alive->header.prog_name);
		nodelay(stdscr, FALSE);
		getch();
	}
	destroy_all(env, 1);
	clear();
	endwin();
	return (1);
}

int		display_start(t_env *env)
{
	int i;

	i = 0;
	if (env->option.visu)
		return (1);
	ft_printf("Introducing contestants...\n");
	while (ft_strlen(env->champions[i].file) && i < env->nb_players)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			env->champions[i].player_id, env->champions[i].header.prog_size,
			env->champions[i].header.prog_name,
			env->champions[i].header.comment);
		i++;
	}
	return (1);
}
