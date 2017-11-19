/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:10:14 by juspende          #+#    #+#             */
/*   Updated: 2017/11/17 10:36:24 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include "../includes/fillit.h"
#include <fcntl.h>

t_bloc		*get_file(char *file)
{
	int		fd;
	int		rd;
	char	*buf;
	t_bloc	*begin_list;
	int		i;

	i = -1;
	rd = 1;
	begin_list = NULL;
	if (file)
		fd = open(file, O_RDONLY);
	buf = malloc(BUF_SIZE);
	while (rd != 0)
	{
		if (++i > 26)
			return (NULL);
		rd = read(fd, buf, BUF_SIZE);
		if (buf[BUF_SIZE - 1] != '\n' && rd != BUF_SIZE - 1)
			return (begin_list);
		if (i == 25 && buf[BUF_SIZE - 1] == '\n')
			return (NULL);
		buf[BUF_SIZE - 1] = '\0';
		ft_list_push_back(&begin_list, ft_strsplit(buf, '\n'));
	}
	return (begin_list);
}

int			main(int argc, char **argv)
{
	t_bloc		*bloc;
	t_solution	*solution;
	char		***tab;

	if ((solution = malloc(sizeof(t_solution))) == NULL ||
	   (solution->so = malloc(sizeof(char *) * (4096))) == NULL)
		return (-1);
	solution->so[0] = NULL;
	if (argc != 2)
		ft_putstr_fd("usage: ./fillit file\n", 0);
	if ((bloc = get_file(argv[1])) == NULL)
		ft_putstr_fd("error\n", 0);
	else if (verification(bloc) == 0)
		ft_putstr_fd("error\n", 0);
	if (argc != 2 || (bloc = get_file(argv[1])) == NULL || verification(bloc)
			== 0)
		return (0);
	tab = lst_to_tab(bloc);
	get_my_letters(tab);
	clear_tabs(tab);
	resolve(tab, ft_list_size(bloc), solution);
	return (0);
}
