/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:26:07 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 14:54:57 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ft_aff(t_asm *strukt, char *s)
{
	unsigned int	tmp;
	int				i;
	char			inst;

	i = ft_find_instruction(s);
	ft_check_instruction_line(s + i, 1, "2");
	inst = 16;
	tmp = ft_atoi(s + i + 1);
	ft_write(strukt, &inst, 1);
	ft_write(strukt, "@", 1);
	ft_write(strukt, &tmp, 1);
	strukt->size += 3;
}

static void	ft_ext_one(t_asm *strukt, char *s, int line, t_ins *t)
{
	if (s[t->i] == DIRECT_CHAR)
	{
		if (s[t->i + 1] == LABEL_CHAR)
			t->tp = ft_find_label(strukt, s + t->i + 2, line);
		else
			t->tp = ft_atoi(s + t->i + 1);
		strukt->size += 4;
		ft_write_ui(t->tp, strukt);
	}
	else
	{
		if (s[t->i] == LABEL_CHAR)
		{
			t->tp = ft_find_label(strukt, s + t->i + 1, line);
			ft_write_us(t->tp, strukt);
			strukt->size += 2;
		}
		else
		{
			t->tmp = (unsigned short)ft_atoi(s + t->i);
			ft_write_us(t->tmp, strukt);
			strukt->size += 2;
		}
	}
}

void		ft_ld_lld(t_asm *strukt, char *s, char opcode, int line)
{
	t_ins	t;

	t.i = ft_find_instruction(s);
	ft_check_instruction_line(s + t.i, 2, "25");
	t.inst = opcode;
	strukt->size += 2;
	ft_write(strukt, &t.inst, 1);
	t.inst = ft_write_codage(s + t.i);
	ft_write(strukt, &t.inst, 1);
	ft_ext_one(strukt, s, line, &t);
	while (s[t.i] != SEPARATOR_CHAR)
		t.i++;
	if (s[t.i + 1] == ' ' || s[t.i + 1] == '\t')
		t.i++;
	if (s[t.i] == ' ' || s[t.i] == '\t')
	{
		while (s[t.i] == ' ' || s[t.i] == '\t')
			t.i++;
		t.i--;
	}
	t.tmp = (char)ft_atoi(s + t.i + 2);
	ft_write(strukt, &t.tmp, 1);
	strukt->size += 1;
}

int			ft_find_instruction(char *s)
{
	int i;

	i = 0;
	while (s[i] == 32 || s[i] == '\t')
		i++;
	while (s[i] && s[i] != 32 && s[i] != '\t')
		i++;
	while (s[i] == 32 || s[i] == '\t')
		i++;
	return (i);
}
