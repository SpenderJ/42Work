/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:25:41 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 14:54:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_ext_two(t_asm *strukt, char *s, int line, t_ins *t)
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
	else if (s[t->i] == 'r')
	{
		t->tmp = (char)ft_atoi(s + t->i + 1);
		ft_write(strukt, &t->tmp, 1);
		strukt->size += 1;
	}
	else
		ft_ext_two(strukt, s, line, t);
	while (s[t->i] != SEPARATOR_CHAR)
		t->i++;
	t->i++;
	while (s[t->i] == ' ' || s[t->i] == '\t')
		t->i++;
}

void		ft_and_xor_or(t_asm *strukt, char *s, char opcode, int line)
{
	t_ins	t;

	t.i = ft_find_instruction(s);
	ft_check_instruction_line(s + t.i, 3, "277");
	t.inst = opcode;
	strukt->size += 2;
	ft_write(strukt, &t.inst, 1);
	t.inst = ft_write_codage(s + t.i);
	ft_write(strukt, &t.inst, 1);
	ft_ext_one(strukt, s, line, &t);
	ft_ext_one(strukt, s, line, &t);
	t.tmp = (char)ft_atoi(s + t.i + 1);
	ft_write(strukt, &t.tmp, 1);
	strukt->size += 1;
}
