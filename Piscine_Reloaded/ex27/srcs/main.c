/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 01:20:26 by juspende          #+#    #+#             */
/*   Updated: 2017/07/18 02:50:38 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buffer[4096];

	if (argc > 2)
		return (ft_putsterr("Too many arguments.\n"));
	if (argc < 2)
		return (ft_putsterr("File name missing.\n"));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	while ((ret = read(fd, buffer, 1)) != -1 && ret != 0)
		ft_putstr(buffer);
	return (0);
}
