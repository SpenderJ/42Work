/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 09:49:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/08/19 19:56:03 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

long	ft_atoi_l(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (((9 <= str[i]) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while ((str[i] != '\0') && ('0' <= str[i]) && (str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

int		ft_is_valid(char **argv, char *str, int min)
{
	int	i;
	int	res;

	i = 0;
	res = -2;
	if (str && min == -1)
		i++;
	while (str[i] != '\0' && ft_isdigit((int)(str[i])))
		i++;
	if (str[i] != '\0' || (!((res = ft_atoi_l(str)) >= min)
		|| !(res < INT_MAX)) || (min == -1 && res != -1 && res != 0 && res != 1
		&& res != 2 && res != 4 && res != 8 && res != 16) || (min == 1
			&& (res < 1 || res > MAX_PLAYERS)))
		display_usage(argv);
	return (1);
}

int		search_options(t_env *env, char **argv, int argc, int i)
{
	int ret;
	int check;

	ret = 0;
	check = argc - (i + 1);
	if (!ft_strcmp(argv[i], "-a") && (ret = 1))
		env->option.a = 1;
	else if ((!ft_strcmp(argv[i], "-d") || !ft_strcmp(argv[i], "-dump"))
			&& check > 0 && (ret = 2) && ft_is_valid(argv, argv[i + 1], 0))
		env->option.d = ft_atoi(argv[i + 1]);
	else if (!ft_strcmp(argv[i], "-s") && check > 0 && (ret = 2)
			&& ft_is_valid(argv, argv[i + 1], 0))
		env->option.s = ft_atoi(argv[i + 1]);
	else if (!ft_strcmp(argv[i], "-n") && check > 0
		&& ft_is_valid(argv, argv[i + 1], 1) && (ret = 3))
		env->attr_id[0][env->nb_players] = ft_atoi(argv[i + 1]);
	else if (!ft_strcmp(argv[i], "-v") && check > 0 && (ret = 2)
			&& ft_is_valid(argv, argv[i + 1], -1))
		env->option.v = ft_atoi(argv[i + 1]);
	else if (!ft_strcmp(argv[i], "-visu") && (ret = 1))
		env->option.visu = 1;
	return (ret);
}

int		ft_is_doublon_int(t_env *env)
{
	int i;
	int j;

	i = -1;
	while (++i < env->nb_players)
	{
		j = i;
		while (++j < env->nb_players)
			if (env->attr_id[0][i] != 0
					&& (env->attr_id[0][i] == env->attr_id[0][j]
				|| env->attr_id[0][i] > env->nb_players))
				return (1);
	}
	return (0);
}

int		check_options(char **argv, int argc, t_env *env)
{
	int	i;
	int	ret;

	i = 1;
	while (argv[i])
	{
		if (!(ret = search_options(env, argv, argc, i)) || ret == 3)
		{
			if (env->nb_players < MAX_PLAYERS)
			{
				env->attr_id[1][env->nb_players] = i + (ret ? ret - 1 : 0);
				env->nb_players++;
			}
			else
				display_errors("Too many champions");
		}
		while (--ret > 0)
			i++;
		i++;
	}
	if (!(env->nb_players) || ft_is_doublon_int(env))
		display_usage(argv);
	ft_sort_id_and_create_players(env, argv);
	return (1);
}
