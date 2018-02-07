/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:21:43 by juspende          #+#    #+#             */
/*   Updated: 2018/02/07 12:17:53 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	get_input(t_lines *lines, int *nb_nodes_expected)
{
	char	*str;
	int		stop;
	int		part;

	*nb_nodes_expected = 2;
	stop = 0;
	part = 0;
	while (!stop)
	{
		if ((str = NULL) == NULL && get_next_line(0, &str) != 1)
			break ;
		if (str[0] != '#')
		{
			if (part == 0)
				part = 1;
			else if (part == 1)
				get_part1(nb_nodes_expected, str, &stop, &part);
			if (part == 2)
				get_part2(str, &stop);
		}
		if (!stop)
			add_line(lines, str);
	}
	if (str)
		free(str);
}

void	get_part1(int *nb_nodes_expected, char *str, int *stop, int *part)
{
	char **words;

	words = ft_strsplit(str, ' ');
	if (words[0] == NULL || words[1] == NULL || words[2] == NULL)
		*part = 2;
	else if (*nb_nodes_expected == MAX_NB_NODES)
		*stop = 1;
	else
		(*nb_nodes_expected)++;
	free_words(words);
}

void	get_part2(char *str, int *stop)
{
	static int	nb_links = 0;
	char		**words;

	words = ft_strsplit(str, '-');
	if (words[0] == NULL || words[1] == NULL || nb_links == MAX_NB_LINKS)
		*stop = 1;
	else
		nb_links++;
	free_words(words);
}

void	free_words(char **words)
{
	int i;

	i = -1;
	if (!words)
		return ;
	while (words[++i] != NULL)
		free(words[i]);
	free(words);
}
