/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:20:53 by juspende          #+#    #+#             */
/*   Updated: 2018/07/12 13:41:07 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_compare_macro(void)
{
	char tmp;

	tmp = COMMENT_CHAR;
	if (tmp == LABEL_CHAR || tmp == DIRECT_CHAR || tmp == SEPARATOR_CHAR)
		ft_exit("Wrong MACRO");
	if (LABEL_CHAR == DIRECT_CHAR || LABEL_CHAR == SEPARATOR_CHAR)
		ft_exit("Wrong MACRO");
	if (DIRECT_CHAR == SEPARATOR_CHAR)
		ft_exit("Wrong MACRO");
}

static void	ft_check_point(void)
{
	if (NAME_CMD_STRING[0] != '.')
		ft_exit("Must begin by '.'");
	if (COMMENT_CMD_STRING[0] != '.')
		ft_exit("Must begin by '.'");
}

static void	ft_check_label_chars(void)
{
	int i;

	i = -1;
	if (!LABEL_CHARS)
		ft_exit("LABEL_CHARS doesn t exist.");
	if (ft_strlen(LABEL_CHARS) == 0)
		ft_exit("LABEL_CHARS can t be empty.");
	while (LABEL_CHARS[++i])
	{
		if (LABEL_CHARS[i] == LABEL_CHAR || LABEL_CHARS[i] == DIRECT_CHAR)
			ft_exit("MACRO forbidden in LABEL_CHARS.");
		if (LABEL_CHARS[i] == SEPARATOR_CHAR || LABEL_CHARS[i] == COMMENT_CHAR)
			ft_exit("MACRO forbidden in LABEL_CHARS.");
	}
}

static void	ft_check_name_and_comment(void)
{
	if (ft_strcmp(NAME_CMD_STRING, COMMENT_CMD_STRING) == 0)
		ft_exit("NAME_CMD_STRING can t be same than COMMENT_CMD_STRING");
	if (ft_strlen(NAME_CMD_STRING) > PROG_NAME_LENGTH)
		ft_exit("NAME_CMD_STRING too big.");
	if (ft_strlen(COMMENT_CMD_STRING) > COMMENT_LENGTH)
		ft_exit("COMMENT_CMD_STRING too big");
}

void		ft_check_header(void)
{
	ft_compare_macro();
	ft_check_point();
	ft_check_name_and_comment();
	ft_check_label_chars();
}
