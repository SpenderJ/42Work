/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:11:20 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/24 12:53:49 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

void		ft_exit(char *str)
{
	write(2, "Error. ", 7);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}

static void	ft_err_one(void)
{
	ft_put("Usage: ./asm [-va] <source-file.s>", '\n', 2, 0);
	ft_put("-v : Instead of creating a .cor file, print the code.", '\n', 2, 0);
	ft_put("-a : Create the .cor file and print the result", '\n', 2, 0);
	ft_put("in hexadecimal.", '\n', 2, 0);
	ft_put("-b : Create the .cor file and print evry lines &", '\n', 2, 0);
	ft_put("the hexa code corresponding", '\n', 2, 0);
}

void		ft_error(size_t id_error, char *name)
{
	if (id_error == 1)
		ft_put("Malloc failed with", 32, 2, 0);
	else if (id_error == 2)
		ft_err_one();
	else if (id_error == 3)
		ft_put("Can't read source file", 32, 2, 0);
	else if (id_error == 4)
		ft_put("wrong number of .name/.comment of", 32, 2, 0);
	else if (id_error == 5)
		ft_put("wrong name/comment's syntax of", 32, 2, 0);
	else if (id_error == 6)
		ft_put("Champion name/comment too long.", 10, 2, 0);
	else if (id_error == 7)
		ft_put("COREWAR_EXEC_MAGIC must be 0xea83f3.", 10, 2, 0);
	else if (id_error == 8)
		ft_put("Can't create cor file.", 10, 2, 0);
	else if (id_error == 9)
		ft_put(".cor file too big.", 10, 2, 0);
	if (name)
		ft_put(name, '\n', 2, 0);
	exit(1);
}
