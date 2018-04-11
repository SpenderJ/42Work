/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:11:13 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/06 13:08:11 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			ft_open_check_and_get_file(t_asm *strukt, char *cpp)
{
	int		fd;
	int		ret;
	char	*str_gnl;

	if ((fd = open(cpp, O_RDONLY)) < 2)
		ft_error(3, cpp);
	if (ft_strlen(cpp) < 2)
		ft_error(3, cpp);
	if (cpp[ft_strlen(cpp) - 1] != 's')
		ft_error(3, cpp);
	if (cpp[ft_strlen(cpp) - 2] != '.')
		ft_error(3, cpp);
	while ((ret = get_next_line(fd, &str_gnl)) == 1)
	{
		strukt->file = ft_malloc_tabtab(strukt->file, str_gnl);
		ft_strdel(&str_gnl);
	}
	if (ret != 0)
		ft_error(3, cpp);
	strukt->file_s_name = ft_strdup(cpp);
	if (strukt->file_s_name == NULL)
		ft_error(1, "strukt->file_s_name");
	close(fd);
}

static t_asm	*ft_init_variables(int c, char **v)
{
	t_asm	*strukt;

	if (!(strukt = (t_asm *)malloc(sizeof(t_asm))))
		ft_error(1, "strukt");
	if ((strukt->ac = c) == 1)
		ft_error(2, NULL);
	strukt->av = v;
	strukt->file = NULL;
	strukt->file_s_name = NULL;
	strukt->tab_label = NULL;
	strukt->bool_name = 0;
	strukt->bool_comment = 0;
	strukt->list = NULL;
	strukt->instruction = NULL;
	strukt->bool_header = 0;
	strukt->size = 0;
	strukt->path = NULL;
	strukt->a = 0;
	strukt->h = 0;
	if ((strukt->header.magic = COREWAR_EXEC_MAGIC) != 0xea83f3)
		ft_error(7, NULL);
	strukt->header.prog_size = 0;
	return (strukt);
}

static t_asm	*ft_ins(t_asm *strukt)
{
	(strukt->a == 1) ? ft_put("magic number :", '\n', 1, 0) : 0;
	ft_write_magic_number(strukt);
	(strukt->a == 1) ? ft_put("\nname:", '\n', 1, 0) : 0;
	ft_write_name(strukt);
	if (strukt->a == 1)
	{
		strukt->a = 0;
		ft_write_prog_size(strukt);
		strukt->a = 1;
	}
	else
		ft_write_prog_size(strukt);
	(strukt->a == 1) ? ft_put("\ncomment:", '\n', 1, 0) : 0;
	ft_write_comment(strukt);
	(strukt->a == 1) ? ft_put("\nins:", '\n', 1, 0) : 0;
	ft_write_instructions(strukt);
	(strukt->a == 1) ? ft_put("\nprogsize:", '\n', 1, 0) : 0;
	strukt->header.prog_size = strukt->size;
	if (CHAMP_MAX_SIZE < strukt->size)
		ft_error(9, NULL);
	ft_write_prog_size(strukt);
	return (strukt);
}

static void		ft_finish_him(t_asm *strukt)
{
	write(1, "Writing output program to ", 26);
	write(1, strukt->path, ft_strlen(strukt->path));
	write(1, "\n", 1);
}

int				main(int c, char **v)
{
	t_asm *strukt;

	strukt = ft_init_variables(c, v);
	ft_check_header();
	ft_open_check_and_get_file(strukt, v[c - 1]);
	if (!strukt->file)
		ft_exit("Incorrect file.");
	strukt = ft_check_file_s(strukt);
	if (ft_strcmp(v[1], "-v") == 0)
		ft_print_file(strukt->file);
	else
	{
		strukt->fd_cor = -1;
		strukt = ft_ins(strukt);
		strukt = ft_create_file_cor(strukt);
		if (strukt->size == 0)
			ft_exit(CYA"NO IA"RES);
		if (ft_strcmp(v[1], "-a") == 0 || ft_strcmp(v[1], "-b") == 0)
			strukt->a = v[1][1] - 0x60;
		strukt->size = 0;
		strukt = ft_ins(strukt);
		(strukt->a != 0) ? write(1, "\n", 1) : 0;
		ft_finish_him(strukt);
	}
	return (0);
}
