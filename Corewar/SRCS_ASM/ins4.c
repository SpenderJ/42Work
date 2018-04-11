/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:56:23 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/05 13:56:35 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	ft_ext_one(t_asm *strukt, char *s, int line, t_instruction *t)
{
	if (s[t->i] == 'r')
	{
		t->tmp = (char)ft_atoi(s + t->i + 1);
		ft_write(strukt, &t->tmp, 1);
		strukt->size += 1;
	}
	else
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
}

void		ft_st(t_asm *strukt, char *s, char opcode, int line)
{
	t_instruction	t;

	t.i = ft_find_instruction(s);
	ft_check_instruction_line(s + t.i, 2, "32");
	t.inst = opcode;
	strukt->size += 2;
	ft_write(strukt, &t.inst, 1);
	t.inst = ft_write_codage(s + t.i, strukt);
	ft_write(strukt, &t.inst, 1);
	t.tmp = (char)ft_atoi(s + t.i + 1);
	ft_write(strukt, &t.tmp, 1);
	strukt->size += 1;
	while (s[t.i] != SEPARATOR_CHAR)
		t.i++;
	t.i++;
	while (s[t.i] == ' ' || s[t.i] == '\t')
		t.i++;
	ft_ext_one(strukt, s, line, &t);
}
