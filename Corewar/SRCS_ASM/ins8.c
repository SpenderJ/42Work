/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins8.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 12:41:33 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/24 12:54:56 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

static void	ft_ext_three(t_asm *strukt, char *s, int line, t_instruction *t)
{
	while (s[t->i] != SEPARATOR_CHAR)
		t->i++;
	t->i++;
	while (s[t->i] == ' ' || s[t->i] == '\t')
		t->i++;
	if (s[t->i] == 'r')
	{
		t->tmp = (char) ft_atoi(s + t->i + 1);
		ft_write(strukt, &t->tmp, 1);
		strukt->size += 1;
	}
	else
	{
		if (s[t->i + 1] == LABEL_CHAR)
			t->tmp = (unsigned short)ft_find_label(strukt, s + t->i + 2,
				strukt->first, line);
		else
			t->tmp = ft_atoi(s + t->i + 1);
		strukt->size += 2;
		ft_write_us(t->tmp, strukt);
	}
	while (s[t->i] != SEPARATOR_CHAR)
		t->i++;
	t->i++;
}

static void	ft_ext_two(t_asm *strukt, char *s, int line, t_instruction *t)
{
	if (s[t->i] == LABEL_CHAR)
	{
		t->tp = ft_find_label(strukt, s + t->i + 1, strukt->first, line);
		ft_write_us(t->tp, strukt);
		strukt->size += 2;
	}
	else
	{
		t->tmp = (unsigned short) ft_atoi(s + t->i);
		ft_write_us(t->tmp, strukt);
		strukt->size += 2;
	}
}

static void	ft_ext_one(t_asm *strukt, char *s, int line, t_instruction *t)
{
	if (s[t->i + 1] == LABEL_CHAR)
		t->tmp = ft_find_label(strukt, s + t->i + 2, strukt->first, line);
	else
		t->tmp = ft_atoi(s + t->i + 1);
	strukt->size += 2;
	ft_write_us(t->tmp, strukt);
}

void		ft_ldi_lldi(t_asm *strukt, char *s, char opcode, int line)
{
	t_instruction	t;

	t.i = ft_find_instruction(s);
	ft_check_instruction_line(s + t.i, 3, "267");
	t.inst = opcode;
	strukt->size += 2;
	ft_write(strukt, &t.inst, 1);
	t.inst = ft_write_codage(s + t.i, strukt);
	ft_write(strukt, &t.inst, 1);
	if (s[t.i] == DIRECT_CHAR)
		ft_ext_one(strukt, s, line, &t);
	else if (s[t.i] == 'r')
	{
		t.tmp = (char) ft_atoi(s + t.i + 1);
		ft_write(strukt, &t.tmp, 1);
		strukt->size += 1;
	}
	else
		ft_ext_two(strukt, s, line, &t);
	ft_ext_three(strukt, s, line, &t);
	while (s[t.i] == ' ' || s[t.i] == '\t')
		t.i++;
	t.tmp = (char) ft_atoi(s + t.i + 1);
	ft_write(strukt, &t.tmp, 1);
	strukt->size += 1;
}
