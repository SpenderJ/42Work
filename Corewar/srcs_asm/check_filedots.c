/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filedots.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:19:54 by juspende          #+#    #+#             */
/*   Updated: 2018/07/12 13:40:40 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char		ft_check_useless_line(char *str)
{
	int	index;
	int	bool_sh;

	index = -1;
	bool_sh = 0;
	if (str[0] == '\0')
		return (0);
	while (str[++index])
	{
		if (str[index] == COMMENT_CHAR)
		{
			bool_sh = 1;
			break ;
		}
		else
		{
			if (str[index] != '\t' && str[index] != 32)
				if (bool_sh != 1)
					return (1);
		}
	}
	return (0);
}

static t_asm	*ft_check_nme(t_asm *strukt, char *str, int ind, int len)
{
	ind = 0;
	len = 0;
	while (str[ind] == 32 || str[ind] == '\t')
		ind++;
	if (ft_strncmp(str + ind, NAME_CMD_STRING, 5) == 0)
	{
		strukt->bool_header++;
		ind += 5;
		strukt->bool_name++;
		while (str[ind] == 32 || str[ind] == '\t')
			ind++;
		(str[ind++] != '\"') ? ft_error(5, strukt->av[strukt->ac - 1]) : 0;
		while (str[ind] && str[ind] != '\"' && len < PROG_NAME_LENGTH)
		{
			strukt->header.prog_name[len] = str[ind];
			len++;
			ind++;
		}
		strukt->header.prog_name[len] = '\0';
		(str[ind] != '\"') ? ft_error(5, strukt->av[strukt->ac - 1]) : 0;
		(len > PROG_NAME_LENGTH) ? ft_error(6, NULL) : 0;
		(ft_check_useless_line(str + ind + 1) == 1) ? ft_exit("") : 0;
	}
	return (strukt);
}

static t_asm	*ft_check_comments(t_asm *strukt, char *str, int ind, int len)
{
	ind = 0;
	len = 0;
	while (str[ind] == 32 || str[ind] == '\t')
		ind++;
	if (ft_strncmp(str + ind, COMMENT_CMD_STRING, 8) == 0)
	{
		strukt->bool_header++;
		strukt->bool_comment++;
		ind += 8;
		while (str[ind] == 32 || str[ind] == '\t')
			ind++;
		(str[ind++] != '\"') ? ft_error(5, strukt->av[strukt->ac - 1]) : 0;
		while (str[ind] && str[ind] != '\"' && len < COMMENT_LENGTH)
		{
			strukt->header.comment[len] = str[ind];
			len++;
			ind++;
		}
		strukt->header.comment[len] = '\0';
		(str[ind] != '\"') ? ft_error(5, strukt->av[strukt->ac - 1]) : 0;
		(len > COMMENT_LENGTH) ? ft_error(6, NULL) : 0;
		(ft_check_useless_line(str + ind + 1) == 1) ? ft_exit("") : 0;
	}
	return (strukt);
}

t_asm			*ft_check_file_s(t_asm *strukt)
{
	int	index;

	index = -1;
	while (strukt->file[++index])
	{
		if (ft_check_useless_line(strukt->file[index]) == 1)
		{
			if (strukt->bool_name == 1 && strukt->bool_comment == 1)
			{
				strukt->first = index;
				ft_check_asm(strukt, index - 1);
				break ;
			}
			strukt = ft_check_nme(strukt, strukt->file[index], 0, 0);
			strukt = ft_check_comments(strukt, strukt->file[index], 0, 0);
		}
		if (strukt->bool_name > 1 || strukt->bool_comment > 1)
			ft_error(4, strukt->av[strukt->ac - 1]);
	}
	if (strukt->bool_name != 1 || strukt->bool_comment != 1)
		ft_error(4, strukt->av[strukt->ac - 1]);
	return (strukt);
}
