/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 09:51:58 by juspende          #+#    #+#             */
/*   Updated: 2018/04/24 12:48:06 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_params(t_gen *params)
{
	int		i;
	int		n;
	t_player	*tmp;

	i = 1;
	ft_printf("Print Params\n");
	ft_printf("number of players = %d\n", params->nb_players);
	ft_printf("dump = %d\n", params->dump);
	n = params->nb_players;
	tmp = params->players;
	while (i <= n)
	{
		if (!tmp)
			{
				ft_printf("Error in list of players for player %d, aborting...\n", i);
				break ;
			}
		ft_printf("-----------------------------\n");
		ft_printf("Printing info for player = %d\n", i);
		ft_printf("-----------------------------\n");
		ft_printf("·····number = %d\n", tmp->number);
		ft_printf("·····name = %s\n", tmp->name);
		ft_printf("·····comment = %s\n", tmp->comment);
		// ft_printf("·····instructions = %s\n", tmp->instructions);
		ft_printf("·····instructions = ");
		print_arg(tmp->instructions, tmp->len - PROG_NAME_LENGTH - COMMENT_LENGTH - MAGIC_NUMBER_SIZE, 'h');
		ft_printf("\n");
		ft_printf("·····length of file = %d\n", tmp->len);
		tmp = tmp->next;
		i++;
	}
}

void	print_arg(char *arg, int len, int option)
{
	int	i;

	if ((i = -1) == -1 && option == 'c')
	{
		//ft_printf("Print Arg\nCHAR mode\n");
		while (++i < len)
			arg[i] == 0 ? ft_printf("%c", '.') : ft_printf("%c", arg[i]);
	}
	else if (option == 'h')
	{
		//ft_printf("Print Arg\nHEX mode\n|");
		while (++i < len)
		{
			arg[i] == 0 ? ft_printf(".") : ft_printf("%x", arg[i]);
			ft_printf("|");
		}
	}
	else if (option == 'd')
	{
		// ft_printf("Print Arg\nDEC mode\n|");
		while (++i < len)
		{
			arg[i] == 0 ? ft_printf(".") : ft_printf("%d", arg[i]);
			ft_printf("|");
		}
	}
	ft_printf("\n");
}

int	ft_b_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
