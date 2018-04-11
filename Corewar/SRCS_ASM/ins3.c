/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:52:34 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/06 13:12:47 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		ft_live(t_asm *strukt, char *s, int line)
{
	unsigned int	tmp;
	int				i;
	char			inst;

	i = ft_find_instruction(s);
	ft_check_instruction_line(s + i, 1, "4");
	inst = 1;
	if (s[i + 1] == LABEL_CHAR)
	{
		tmp = ft_find_label(strukt, s + i + 2, strukt->first, line);
	}
	else
		tmp = ft_atoi(s + i + 1);
	ft_write(strukt, &inst, 1);
	ft_write_ui(tmp, strukt);
	strukt->size += 5;
}

static void	ft_ext_three(t_asm *strukt, char *s, int line, t_instruction *t)
{
	while (s[t->i] != SEPARATOR_CHAR)
		t->i++;
	t->i++;
	while (s[t->i] == ' ' || s[t->i] == '\t')
		t->i++;
	if (s[t->i] == DIRECT_CHAR)
	{
		if (s[t->i + 1] == LABEL_CHAR)
			t->tmp = ft_find_label(strukt, s + t->i + 2, strukt->first, line);
		else
			t->tmp = ft_atoi(s + t->i + 1);
		strukt->size += 2;
		ft_write_us(t->tmp, strukt);
	}
	else
	{
		t->tmp = (char)ft_atoi(s + t->i + 1);
		ft_write(strukt, &t->tmp, 1);
		strukt->size += 1;
	}
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
		t->tmp = (unsigned short)ft_atoi(s + t->i);
		ft_write_us(t->tmp, strukt);
		strukt->size += 2;
	}
}

static void	ft_ext_one(t_asm *strukt, char *s, t_instruction *t, char *opcode)
{
	t->i = ft_find_instruction(s);
	ft_check_instruction_line(s + t->i, 3, "672");
	t->inst = *opcode;
	strukt->size += 2;
	ft_write(strukt, &t->inst, 1);
	t->inst = ft_write_codage(s + t->i, strukt);
	ft_write(strukt, &t->inst, 1);
	t->tmp = (char)ft_atoi(s + t->i + 1);
	ft_write(strukt, &t->tmp, 1);
	strukt->size += 1;
	while (s[t->i] != SEPARATOR_CHAR)
		t->i++;
	t->i++;
	while (s[t->i] == ' ' || s[t->i] == '\t')
		t->i++;
}

void		ft_sti(t_asm *strukt, char *s, char opcode, int line)
{
	t_instruction	t;

	ft_ext_one(strukt, s, &t, &opcode);
	if (s[t.i] == DIRECT_CHAR)
	{
		if (s[t.i + 1] == LABEL_CHAR)
			t.tmp = ft_find_label(strukt, s + t.i + 2, strukt->first, line);
		else
			t.tmp = ft_atoi(s + t.i + 1);
		strukt->size += 2;
		ft_write_us(t.tmp, strukt);
	}
	else if (s[t.i] == 'r')
	{
		t.tmp = (char)ft_atoi(s + t.i + 1);
		ft_write(strukt, &t.tmp, 1);
		strukt->size += 1;
	}
	else
		ft_ext_two(strukt, s, line, &t);
	ft_ext_three(strukt, s, line, &t);
}
