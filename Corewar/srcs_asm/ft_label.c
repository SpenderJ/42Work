/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:23:38 by juspende          #+#    #+#             */
/*   Updated: 2018/08/21 14:54:36 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_less_ext(t_asm *s_asm, int line, int *i)
{
	while (s_asm->file[line][*i] && s_asm->file[line][*i] != ' ' &&
		s_asm->file[line][*i] != '\t' && s_asm->file[line][*i] != COMMENT_CHAR
		&& s_asm->file[line][*i] != LABEL_CHAR)
		*i = *i + 1;
	if (s_asm->file[line][*i] == LABEL_CHAR)
	{
		*i = *i + 1;
		while (s_asm->file[line][*i] == ' ' || s_asm->file[line][*i] == '\t')
			*i = *i + 1;
		while (s_asm->file[line][*i] && s_asm->file[line][*i] != ' ' &&
			s_asm->file[line][*i] != '\t' && s_asm->file[line][*i] !=
			COMMENT_CHAR && s_asm->file[line][*i] != LABEL_CHAR)
			*i = *i + 1;
	}
}

static int		ft_less(t_asm *s_asm, int line, int actual, int val)
{
	int		i;
	char	opc;
	char	dir;

	while (line < actual)
	{
		i = 0;
		while (s_asm->file[line][i] == ' ' || s_asm->file[line][i] == '\t')
			i++;
		ft_op_dir(s_asm->file[line] + i, &opc, &dir);
		ft_less_ext(s_asm, line, &i);
		while (s_asm->file[line][i] == ' ' || s_asm->file[line][i] == '\t')
			i++;
		if (s_asm->file[line][i] != '\0' && s_asm->file[line][i] !=
			COMMENT_CHAR)
		{
			val = (opc == 1) ? val + 2 : val + 1;
			val += ft_count(s_asm->file[line] + i, dir, 0);
		}
		line++;
	}
	return (val);
}

static void		ft_greater_ext(t_asm *s_asm, int actual, int *i)
{
	while (s_asm->file[actual][*i] && s_asm->file[actual][*i] != ' ' &&
		s_asm->file[actual][*i] != '\t' && s_asm->file[actual][*i] !=
		COMMENT_CHAR && s_asm->file[actual][*i] != LABEL_CHAR)
		*i = *i + 1;
	if (s_asm->file[actual][*i] == LABEL_CHAR)
	{
		*i = *i + 1;
		while (s_asm->file[actual][*i] == ' ' || s_asm->file[actual][*i] ==
			'\t')
			*i = *i + 1;
		while (s_asm->file[actual][*i] && s_asm->file[actual][*i] != ' ' &&
			s_asm->file[actual][*i] != '\t' && s_asm->file[actual][*i] !=
			COMMENT_CHAR && s_asm->file[actual][*i] != LABEL_CHAR)
			*i = *i + 1;
	}
}

static int		ft_greater(t_asm *s_asm, int line, int actual, int val)
{
	int		i;
	char	opc;
	char	dir;

	while (line > actual)
	{
		i = 0;
		while (s_asm->file[actual][i] == ' ' || s_asm->file[actual][i] == '\t')
			i++;
		ft_op_dir(s_asm->file[actual] + i, &opc, &dir);
		ft_greater_ext(s_asm, actual, &i);
		while (s_asm->file[actual][i] == ' ' || s_asm->file[actual][i] == '\t')
			i++;
		if (s_asm->file[actual][i] != '\0' && s_asm->file[actual][i] !=
			COMMENT_CHAR)
		{
			val = (opc == 1 ? val + 2 : val + 1);
			val += ft_count(s_asm->file[actual] + i, dir, 0);
		}
		actual++;
	}
	return (val);
}

unsigned int	ft_find_label(t_asm *s_asm, char *s, int actual)
{
	unsigned int	address;
	int				line;
	char			*label;
	int				i;

	i = 0;
	address = 0;
	while (s[i] && s[i] != COMMENT_CHAR && s[i] != ' ' && s[i]
		!= '\t' && s[i] != SEPARATOR_CHAR)
		i++;
	label = ft_strjoin_set(ft_strndup(s, i), ":", 1);
	if (((line = ft_find_line(s_asm, label, 0, -1)) - actual) == 0)
	{
		ft_strdel(&label);
		return (0);
	}
	if (line < actual)
		address -= ft_less(s_asm, line, actual, 0);
	if (actual < line)
		address = ft_greater(s_asm, line, actual, 0);
	ft_strdel(&label);
	return (address);
}
