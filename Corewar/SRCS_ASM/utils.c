/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpacaly <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:21:01 by tpacaly           #+#    #+#             */
/*   Updated: 2018/04/05 12:21:02 by tpacaly          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			ft_print_file(char **tab_file)
{
	int index;

	index = -1;
	while (tab_file[++index])
		ft_put(tab_file[index], '\n', 1, 0);
	exit(0);
}

int				ft_find_instruction(char *s)
{
	int i;

	i = 0;
	while (s[i] == 32 || s[i] == '\t')
		i++;
	while (s[i] && s[i] != 32 && s[i] != '\t')
		i++;
	while (s[i] == 32 || s[i] == '\t')
		i++;
	return (i);
}

static char		*ft_trunc_name(t_asm *strukt)
{
	int		index;
	char	*name_trunc;

	index = -1;
	while (strukt->file_s_name[++index])
		;
	while (strukt->file_s_name[index] != '.')
		index--	;
	strukt->file_s_name[index] = '\0';
	if (!(name_trunc = (char *)malloc(sizeof(char) * index + 1)))
		ft_exit("Malloc failed in create_file_core.c");
	name_trunc[index] = 0;
	index = -1;
	while (strukt->file_s_name[++index])
		name_trunc[index] = strukt->file_s_name[index];
	return (name_trunc);
}

t_asm			*ft_create_file_cor(t_asm *strukt)
{
	strukt->path = ft_strjoin_set(ft_trunc_name(strukt), ".cor", 1);
	if (!(strukt->fd_cor =
		open(strukt->path, O_TRUNC | O_RDWR | O_CREAT, 0777 | O_APPEND)))
		ft_error(8, NULL);
	return (strukt);
}
