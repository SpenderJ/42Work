/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_load_players.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:07 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/20 14:25:18 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		ft_size_instruction(const char *s)
{
	unsigned int	i;
	char			*tmp_s;

	tmp_s = (char *)s;
	i = CHAMP_MAX_SIZE - 1;
	while (i != 0 && tmp_s[i] == '\0')
		i--;
	return (i + 1);
}

int		load_players(t_env *env)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (i < env->nb_players)
	{
		k = -1;
		j = (env->champions[i].player_id - 1) * MEM_SIZE / env->nb_players;
		env->champions[i].size =
			ft_size_instruction(env->champions[i].instructions);
		ft_memcpy(&env->arena[j], env->champions[i].instructions,
				env->champions[i].size);
		while (++k < env->champions[i].size)
			env->arena2[j + k] = env->champions[i].player_id;
		i++;
	}
	return (1);
}
