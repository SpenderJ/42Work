/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:19 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/20 17:02:39 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		check_prog_size(char *prog_size, t_env *env)
{
	int	result;
	int	max_size;

	result = ((unsigned char)(prog_size[0]) << 24)
		| ((unsigned char)(prog_size[1]) << 16)
		| ((unsigned char)(prog_size[2]) << 8)
		| (unsigned char)(prog_size[3]);
	max_size = CHAMP_MAX_SIZE;
	if (result < 0 || result > max_size)
		display_errors_with_value(result, 1, env);
	env->champions[env->nb_players].header.prog_size = result;
	return (1);
}

int		check_magic(char *magic, t_env *env)
{
	int check_magic;

	check_magic = COREWAR_EXEC_MAGIC;
	if ((magic[1] << 16 & 0xff0000) == (check_magic & 0xff0000) &&
			(magic[2] << 8 & 0x00ff00) == (check_magic & 0x00ff00) &&
			(magic[3] & 0x0000ff) == (check_magic & 0x0000ff))
		env->champions[env->nb_players].header.magic = COREWAR_EXEC_MAGIC;
	else
		display_errors("Corewar_exec_magic key is not valid.");
	return (1);
}
