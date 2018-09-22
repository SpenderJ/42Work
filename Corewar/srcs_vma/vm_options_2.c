/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_options_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserguie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 16:48:19 by aserguie          #+#    #+#             */
/*   Updated: 2018/08/18 18:16:28 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_rotate(t_env *env, int i)
{
	int j;
	int index;
	int tmp[2];

	j = i - 1;
	index = env->attr_id[0][i] - 1;
	while (++j < index)
	{
		tmp[0] = env->attr_id[0][j + 1];
		tmp[1] = env->attr_id[1][j + 1];
		env->attr_id[0][j + 1] = env->attr_id[0][j];
		env->attr_id[1][j + 1] = env->attr_id[1][j];
		env->attr_id[0][j] = tmp[0];
		env->attr_id[1][j] = tmp[1];
	}
}

void	ft_sort_id_and_create_players(t_env *env, char **argv)
{
	int i;
	int k;

	i = -1;
	while (++i < env->nb_players)
	{
		if (env->attr_id[0][i] == 0 || ((env->attr_id[0][i] < i + 1)
				&& env->attr_id[0][env->attr_id[0][i]] != 0))
			env->attr_id[0][i] = i + 1;
		else if (env->attr_id[0][i] > i + 1)
		{
			ft_rotate(env, i);
			i = -1;
		}
	}
	k = env->nb_players;
	i = -1;
	env->nb_players = 0;
	while (++i < k)
		create_player(argv[env->attr_id[1][i]], env);
}
