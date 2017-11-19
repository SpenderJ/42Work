/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:16:41 by juspende          #+#    #+#             */
/*   Updated: 2017/11/14 11:05:36 by cmalfroy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "../libft/libft.h"
#include "../includes/fillit.h"

int		error(void)
{
	ft_putstr("error\n");
	return (1);
}

int		main(int ac, char **av)
{
	t_list	*list;
	t_map	*map;
	int		fd;

	if (ac == 2 && ((fd = open(av[1], O_RDONLY)) > 0))
	{
		if ((list = read_tetris(fd)) == NULL)
		{
			close(fd);
			return (error());
		}
		close(fd);
		if (ft_lstcount(list) > 26)
			return (error());
		map = solve(list);
		print_map(map);
		free_map(map);
		free_list(list);
		return (0);
	}
	if (ac != 2)
		ft_putstr("usage: fillit input_file\n");
	else
		error();
	return (1);
}
