/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:46:11 by juspende          #+#    #+#             */
/*   Updated: 2018/07/12 13:46:28 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static char	ft_check_char_label(char cara)
{
	int i;
	int error;

	i = 0;
	error = 1;
	while (LABEL_CHARS[i])
	{
		if (LABEL_CHARS[i] == cara)
		{
			error--;
			break ;
		}
		i++;
	}
	return (error);
}

static void	ft_add_to_tab_label(t_asm *s_asm, char *str, int i)
{
	char	*tmp;
	int		index;
	int		nbr;

	index = -1;
	nbr = 0;
	while (++index < i)
	{
		if (str[index] != ' ' && str[index] != '\t')
			nbr++;
	}
	if (!(tmp = (char *)malloc(sizeof(char) * nbr + 1)))
		ft_exit("Malloc failed in check_asm.c");
	tmp[nbr] = 0;
	index = -1;
	nbr = 0;
	while (++index < i)
	{
		if (ft_check_char_label(str[index]))
			ft_exit("Wrong label.");
		if (str[index] != ' ' && str[index] != '\t')
			tmp[nbr++] = str[index];
	}
	s_asm->tab_label = ft_malloc_tabtab(s_asm->tab_label, tmp);
	ft_strdel(&tmp);
}

void		ft_check_asm(t_asm *s_asm, int index)
{
	static int	bool_label = 0;
	int			i;
	int			index_copy;

	bool_label++;
	if (bool_label != 1)
		return ;
	index_copy = index;
	while (s_asm->file[++index])
	{
		i = 0;
		while (s_asm->file[index][i] == '\t' || s_asm->file[index][i] == 32)
			i++;
		if (s_asm->file[index][i] != COMMENT_CHAR)
		{
			while (s_asm->file[index][i] && s_asm->file[index][i] !=
				LABEL_CHAR && s_asm->file[index][i] != 32
				&& s_asm->file[index][i] != '\t')
				i++;
		}
		if (s_asm->file[index][i] == LABEL_CHAR)
			ft_add_to_tab_label(s_asm, s_asm->file[index], i);
	}
}
