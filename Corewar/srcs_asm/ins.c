/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ins.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:24:26 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 14:54:44 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	magic_help(t_asm *strukt)
{
	unsigned long long		car;

	car = COREWAR_EXEC_MAGIC >> 16;
	ft_write(strukt, &car, 1);
	car = COREWAR_EXEC_MAGIC >> 8;
	ft_write(strukt, &car, 1);
	car = COREWAR_EXEC_MAGIC;
	ft_write(strukt, &car, 1);
}

void	ft_write_magic_number(t_asm *strukt)
{
	unsigned long long		car;
	int						help;

	help = strukt->a;
	strukt->a = 0;
	ft_write(strukt, "\0", 1);
	if (COREWAR_EXEC_MAGIC <= 0xFF)
	{
		car = COREWAR_EXEC_MAGIC;
		ft_write(strukt, &car, 1);
	}
	else if (COREWAR_EXEC_MAGIC <= 0xFFFF)
	{
		car = COREWAR_EXEC_MAGIC >> 8;
		ft_write(strukt, &car, 1);
		car = COREWAR_EXEC_MAGIC;
		ft_write(strukt, &car, 1);
	}
	else if (COREWAR_EXEC_MAGIC <= 0xFFFFFF)
		magic_help(strukt);
	strukt->a = help;
}

void	ft_write_prog_size(t_asm *strukt)
{
	int				index;
	unsigned int	tmp;
	int				u;

	index = -1;
	strukt->header.prog_size = strukt->size;
	u = lseek(strukt->fd_cor, 4 + PROG_NAME_LENGTH, SEEK_SET);
	while (++index < 4)
		ft_write(strukt, "\0", 1);
	tmp = strukt->header.prog_size >> 24;
	ft_write(strukt, &tmp, 1);
	tmp = strukt->header.prog_size >> 16;
	ft_write(strukt, &tmp, 1);
	tmp = strukt->header.prog_size >> 8;
	ft_write(strukt, &tmp, 1);
	tmp = strukt->header.prog_size;
	ft_write(strukt, &tmp, 1);
}

void	ft_write_comment(t_asm *strukt)
{
	int		index;
	char	bool_zero;

	index = -1;
	bool_zero = 0;
	while (++index < COMMENT_LENGTH)
	{
		if (bool_zero == 0)
		{
			ft_write(strukt, &strukt->header.comment[index], 1);
			if (strukt->header.comment[index] == 0)
				bool_zero = 1;
		}
		else
			ft_write(strukt, "\0", 1);
	}
	index = -1;
	while (++index < 4)
		ft_write(strukt, "\0", 1);
}

void	ft_write_name(t_asm *strukt)
{
	int		index;
	char	bool_zero;

	index = -1;
	bool_zero = 0;
	while (++index < PROG_NAME_LENGTH)
	{
		if (bool_zero == 0)
		{
			ft_write(strukt, &strukt->header.prog_name[index], 1);
			if (strukt->header.prog_name[index] == 0)
				bool_zero = 1;
		}
		else
			ft_write(strukt, "\0", 1);
	}
}
