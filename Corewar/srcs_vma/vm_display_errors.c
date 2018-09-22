/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_display_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:48:43 by sgauguet          #+#    #+#             */
/*   Updated: 2018/07/05 10:43:12 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	display_errors_with_value(int value, int code, t_env *env)
{
	if (code == 0)
		ft_printf("Can't read source file %s\n",
				env->champions[env->nb_players].file);
	if (code == 1)
		ft_printf("Error: File %s has too large a code (%d bytes > %lu "
			"bytes).\n", env->champions[env->nb_players].file,
			value, CHAMP_MAX_SIZE);
	exit(0);
}

void	display_errors(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(0);
}
