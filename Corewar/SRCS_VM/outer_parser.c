/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outer_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:43:35 by juspende          #+#    #+#             */
/*   Updated: 2018/04/24 10:03:22 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			is_valid_num(char *str)
{
	int		i;
	int		len;

	if ((i = 0) == 0 && str)
	{
		len = ft_strlen(str);
		while (i < len)
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
			{
				//ft_printf("number is IN-valid! (not a number)\n");
				return (0);
			}
			i++;
		}
		if (ft_atoi(str) < 0)
		{
			// ft_printf("number is IN-valid! (atoi doesnt work)\n");
			return (0);
		}
		// ft_printf("number is valid!\n");
		return (1);
	}
	// ft_printf("number is IN-valid! (str does not exist)\n");
	return (0);
}

int			is_valid_dump(t_gen *params, int n_arg, char **av)
{
	// ft_printf("av[1] %s\n", av[1]);
	if (n_arg >= 3 \
			&& !(params->dump) \
			&& !(params->nb_players) \
			&& (is_valid_num(av[2])))
	{
		params->dump = ft_atoi(av[2]);
		return (1);
	}
	// ft_printf("dump is invalid\n");
	return (0);
}

int			is_valid_player(char *arg)
{
	int		len;

	// ft_printf("player to check = %s\n", arg);
	len = ft_strlen(arg);
	// ft_printf("arg : %s\n", arg);
	// ft_printf("arg : %c\n", arg[len]);
	// ft_printf("arg : %c\n", arg[len - 1]);
	// ft_printf("arg : %c\n", arg[len - 2]);
	// ft_printf("arg : %c\n", arg[len - 3]);
	if (len >= 5
			&& arg[len - 1] == 'r'
			&& arg[len - 2] == 'o'
			&& arg[len - 3] == 'c'
			&& arg[len - 4] == '.')
		return (1);
	// ft_printf("player is invalid!\n");
	return (0);
}

int			is_numbered_player(t_gen *params, int i, int n_arg, char **av)
{
	// ft_printf("strcmp |%s| %d\n", av[i], (ft_strcmp("-n", av[i])));
	// ft_printf("i + 2 = %d, n_arg = %d\n", i + 2, n_arg);
	// ft_printf("nb players %d\n",params->nb_players);
	if ((ft_strcmp("-n", av[i]) == 0) \
			&& (i + 2 <= n_arg) \
			&& (params->nb_players < MAX_PLAYERS) \
			&& (is_valid_num(av[i + 1]))
			&& (is_valid_player(av[i + 2])))
	{
		// params->nb_players += 1;
		// init_player(av[i + 2], ft_atoi(av[i + 1]));
		// player_value = ft_atoi(av[i + 1]);
		// ft_printf("is numbered player returning %d\n", ft_atoi(av[i + 1]));
		return (ft_atoi(av[i + 1]));
	}
	// ft_printf("invalid numbered player\n");
	return (0);
}
