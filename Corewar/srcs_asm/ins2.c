/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:24:41 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 16:31:28 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	ft_find_command(char *str, t_asm *strukt, int i, int j)
{
	while (str[i] && (str[i] == 32 || str[i] == '\t'))
		i++;
	if (str[i] && str[i] != COMMENT_CHAR && str[i] != '.')
	{
		j = i;
		while (str[j] && str[j] != 32 && str[j] != '\t')
			j++;
		if (str[j - 1] == LABEL_CHAR)
		{
			i = j;
			while (str[i] && (str[i] == 32 || str[i] == '\t'))
				i++;
			if (str[i] == COMMENT_CHAR)
				return (0);
			j = i;
			while (str[j] && str[j] != 32 && str[j] != '\t')
				j++;
			if (!str[j])
				return (0);
		}
	}
	else
		return (0);
	strukt->ins = str + i;
	return (1);
}

static void	ft_command_ext(char *s, char *tmp, t_asm *strukt, int line)
{
	if (ft_strcmp(tmp, "or") == 0)
		ft_and_xor_or(strukt, s, 7, line);
	else if (ft_strcmp(tmp, "xor") == 0)
		ft_and_xor_or(strukt, s, 8, line);
	else if (ft_strcmp(tmp, "and") == 0)
		ft_and_xor_or(strukt, s, 6, line);
	else if (ft_strcmp(tmp, "zjmp") == 0)
		ft_zjmp(strukt, s, line);
	else if (ft_strcmp(tmp, "ld") == 0)
		ft_ld_lld(strukt, s, 2, line);
	else if (ft_strcmp(tmp, "lld") == 0)
		ft_ld_lld(strukt, s, 13, line);
	else if (ft_strcmp(tmp, "ldi") == 0)
		ft_ldi_lldi(strukt, s, 10, line);
	else if (ft_strcmp(tmp, "lldi") == 0)
		ft_ldi_lldi(strukt, s, 14, line);
	else if (ft_strcmp(tmp, "fork") == 0)
		ft_fork(strukt, s, line);
	else if (ft_strcmp(tmp, "lfork") == 0)
		ft_lfork(strukt, s, line);
	else if (ft_strcmp(tmp, "sub") == 0)
		ft_sub_add(strukt, s, 5);
	else
		ft_exit("Wrong command.");
}

static void	ft_command_2(char *ins, int i)
{
	char	**tmp;
	int		g;

	g = 0;
	if (i == 1)
		write(1, "\n", 1);
	tmp = ft_strsplit(ins, ' ');
	while (tmp[g])
	{
		ft_put(tmp[g], '\t', 1, 1);
		g++;
	}
	write(1, "\t=>\t", 4);
	if (tmp != NULL)
		free(tmp);
	if (ins != NULL)
		ft_strdel(&ins);
}

static void	ft_command(char *s, t_asm *strukt, int line, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strndup(s, ft_strlen(s));
	(strukt->a == 3) ? ft_command_2(tmp2, strukt->h) : ft_strdel(&tmp2);
	(strukt->h == 0 && strukt->a == 3) ? strukt->h = 1 : 0;
	while (s[i] && s[i] != 32 && s[i] != '\t')
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * i + 1)))
		ft_exit("Malloc failed in ins2.c");
	strncpy(tmp, s, i);
	tmp[i] = 0;
	if (ft_strcmp(tmp, "live") == 0)
		ft_live(strukt, s, line);
	else if (ft_strcmp(tmp, "aff") == 0)
		ft_aff(strukt, s);
	else if (ft_strcmp(tmp, "st") == 0)
		ft_st(strukt, s, 3, line);
	else if (ft_strcmp(tmp, "sti") == 0)
		ft_sti(strukt, s, 11, line);
	else if (ft_strcmp(tmp, "add") == 0)
		ft_sub_add(strukt, s, 4);
	else
		ft_command_ext(s, tmp, strukt, line);
	ft_strdel(&tmp);
}

void		ft_write_instructions(t_asm *strukt)
{
	int		index;

	index = -1;
	strukt->a = (strukt->a == 2) ? 3 : strukt->a;
	while (strukt->file[++index])
	{
		if (ft_find_command(strukt->file[index], strukt, 0, 0) == 1)
		{
			ft_command(strukt->ins, strukt, index, 0);
		}
	}
	strukt->a = (strukt->a == 3) ? 2 : strukt->a;
}
