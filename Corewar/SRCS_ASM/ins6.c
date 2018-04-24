/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:36:09 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/24 12:54:44 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	ft_ext_one(t_asm *strukt, char *s, t_instruction *t)
{
	while (s[t->i] != SEPARATOR_CHAR)
		t->i++;
	if (s[t->i + 1] == ' ' || s[t->i + 1] == '\t')
		t->i++;
	if (s[t->i] == ' ' || s[t->i] == '\t')
	{
		while (s[t->i] == ' ' || s[t->i] == '\t')
			t->i++;
		t->i--;
	}
	t->tp = (char) ft_atoi(s + t->i + 2);
	ft_write(strukt, &t->tp, 1);
	strukt->size += 1;
	t->i++;
}

void		ft_sub_add(t_asm *strukt, char *s, char opcode)
{
	t_instruction	t;

	t.i = ft_find_instruction(s);
	ft_check_instruction_line(s + t.i, 3, "222");
	t.inst = opcode;
	strukt->size += 2;
	ft_write(strukt, &t.inst, 1);
	t.inst = ft_write_codage(s + t.i, strukt);
	ft_write(strukt, &t.inst, 1);
	t.tp = (char) ft_atoi(s + t.i + 1);
	ft_write(strukt, &t.tp, 1);
	strukt->size += 1;
	ft_ext_one(strukt, s, &t);
	while (s[t.i] != SEPARATOR_CHAR)
		t.i++;
	t.i = (s[t.i + 1] == ' ' || s[t.i + 1] == '\t') ? t.i + 1 : t.i;
	if (s[t.i] == ' ' || s[t.i] == '\t')
	{
		while (s[t.i] == ' ' || s[t.i] == '\t')
			t.i++;
		t.i--;
	}
	t.tp = (char) ft_atoi(s + t.i + 2);
	ft_write(strukt, &t.tp, 1);
	strukt->size += 1;
}

void		ft_zjmp(t_asm *strukt, char *s, int line)
{
	unsigned short	tmp;
	int				i;
	char			inst;

	i = ft_find_instruction(s);
	ft_check_instruction_line(s + i, 1, "4");
	inst = 9;
	if (s[i + 1] == LABEL_CHAR)
	{
		tmp = ft_find_label(strukt, s + i + 2, strukt->first, line);
	}
	else
		tmp = (unsigned short) ft_atoi(s + i + 1);
	ft_write(strukt, &inst, 1);
	ft_write_us(tmp, strukt);
	strukt->size += 3;
}

void		ft_fork(t_asm *strukt, char *s, int line)
{
	unsigned short	tmp;
	int				i;
	char			inst;

	i = ft_find_instruction(s);
	ft_check_instruction_line(s + i, 1, "4");
	inst = 12;
	if (s[i + 1] == LABEL_CHAR)
	{
		tmp = ft_find_label(strukt, s + i + 2, strukt->first, line);
	}
	else
		tmp = (unsigned short) ft_atoi(s + i + 1);
	ft_write(strukt, &inst, 1);
	ft_write_us(tmp, strukt);
	strukt->size += 3;
}

void		ft_lfork(t_asm *strukt, char *s, int line)
{
	unsigned short	tmp;
	int				i;
	char			inst;

	i = ft_find_instruction(s);
	ft_check_instruction_line(s + i, 1, "4");
	inst = 15;
	if (s[i + 1] == LABEL_CHAR)
	{
		tmp = ft_find_label(strukt, s + i + 2, strukt->first, line);
	}
	else
		tmp = (unsigned short) ft_atoi(s + i + 1);
	ft_write(strukt, &inst, 1);
	ft_write_us(tmp, strukt);
	strukt->size += 3;
}
