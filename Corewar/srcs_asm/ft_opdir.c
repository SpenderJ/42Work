/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:24:10 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 15:24:47 by aserguie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_bool(int i, char *bool_op, char *bool_dir)
{
	if (i == 1)
	{
		*bool_op = 1;
		*bool_dir = 0;
	}
	else if (i == 2)
	{
		*bool_op = 0;
		*bool_dir = 1;
	}
	else if (i == 3)
	{
		*bool_op = 1;
		*bool_dir = 1;
	}
	else if (i == 4)
	{
		*bool_op = 0;
		*bool_dir = 0;
	}
}

static int		ft_fd_inst_2(char *inst, char **at, char **bt, char **ct)
{
	int i;
	int marker;

	i = -1;
	marker = 0;
	while (at[++i])
	{
		if (ft_strcmp(inst, at[i]) == 0)
			return (1);
	}
	i = -1;
	if (marker == 0)
		while (bt[++i])
		{
			if (ft_strcmp(inst, bt[i]) == 0)
				return (2);
			else if (ft_strcmp(inst, ct[i]) == 0)
				return (3);
		}
	if (marker == 0)
		if (ft_strcmp(inst, "live") == 0)
			return (4);
	return (0);
}

static int		ft_fd_inst(char *inst, int tmp)
{
	char *at[10];
	char *bt[4];
	char *ct[4];

	at[0] = "aff";
	at[1] = "st";
	at[2] = "add";
	at[3] = "sub";
	at[4] = "and";
	at[5] = "or";
	at[6] = "xor";
	at[7] = "ld";
	at[8] = "lld";
	at[9] = 0;
	bt[0] = "zjmp";
	bt[1] = "fork";
	bt[2] = "lfork";
	bt[3] = 0;
	ct[0] = "sti";
	ct[1] = "ldi";
	ct[2] = "lldi";
	ct[3] = 0;
	tmp = ft_fd_inst_2(inst, at, bt, ct);
	ft_strdel(&inst);
	return (tmp);
}

void			ft_op_dir(char *s, char *bool_op, char *bool_dir)
{
	int		i;
	int		tmp;
	char	*inst;

	inst = NULL;
	i = 0;
	tmp = 0;
	while (s[i] && s[i] != COMMENT_CHAR && s[i] != ' ' &&
		s[i] != LABEL_CHAR && s[i] != '\t')
		i++;
	if (s[i] == LABEL_CHAR)
	{
		i++;
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		tmp = i;
		while (s[i] && s[i] != COMMENT_CHAR && s[i] != ' ' &&
			s[i] != LABEL_CHAR && s[i] != 9)
			i++;
	}
	inst = ft_strndup(s + tmp, i - tmp);
	if (!inst)
		return ;
	i = ft_fd_inst(inst, tmp);
	ft_bool(i, bool_op, bool_dir);
}
