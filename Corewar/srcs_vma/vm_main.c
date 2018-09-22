/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:22 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/20 14:29:29 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	main(int argc, char **argv)
{
	t_env	env;

	if (argc < 2)
		display_usage(argv);
	init_vm_environment(&env);
	check_options(argv, argc, &env);
	load_players(&env);
	if (env.option.visu)
	{
		env.option.a = 0;
		env.option.d = -1;
		env.option.s = 0;
		env.option.v = 0;
		ft_init_visu(&env);
	}
	init_process_stack(&env);
	env.last_alive = &env.champions[env.nb_players - 1];
	run_the_game(&env, 0, 0, 0);
	display_end(&env);
	return (1);
}
