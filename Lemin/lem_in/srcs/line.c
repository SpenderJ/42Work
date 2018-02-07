/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:22:07 by juspende          #+#    #+#             */
/*   Updated: 2018/02/07 12:18:57 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_line	*alloc_line(void)
{
	t_line *line;

	line = malloc(sizeof(t_line));
	line->next = NULL;
	return (line);
}

void	add_line(t_lines *lines, char *str)
{
	t_line *line;

	line = alloc_line();
	line->str = str;
	if (lines->first == NULL)
		lines->first = line;
	else
		lines->last->next = line;
	lines->last = line;
}

void	free_lines(t_lines *lines)
{
	t_line *line;
	t_line *next;

	line = lines->first;
	while (line != NULL)
	{
		next = line->next;
		if (line->str)
			free(line->str);
		if (line)
			free(line);
		line = next;
	}
	lines->first = NULL;
	lines->last = NULL;
}

void	print_lines(t_lines lines, int nb_lines)
{
	t_line	*line;
	int		i;

	line = lines.first;
	i = -1;
	while (++i < nb_lines)
	{
		ft_printf("%s\n", line->str);
		line = line->next;
	}
}
