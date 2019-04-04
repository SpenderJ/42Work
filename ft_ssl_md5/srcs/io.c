/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juspende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 10:50:41 by juspende          #+#    #+#             */
/*   Updated: 2019/04/04 14:01:37 by juspende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ssl.h"

static int	file_str(int fd, char **str)
{
	char	*tmp;
	char	*tmp2;
	char	*final;

	tmp = NULL;
	final = NULL;
	if ((tmp2 = malloc(sizeof(char) * 2)) == NULL)
		return (0);
	tmp2[0] = 0;
	while (get_next_line(fd, &tmp) > 0)
	{
		final = ft_strjoin(tmp2, tmp);
		free (tmp);
		free (tmp2);
		tmp2 = ft_strdup(final);
	}
	free (tmp2);
	*str = ft_strdup(final);
	free (final);
	return (TRUE);
}

int			io(t_ssl *ssl)
{
	int		fd;
	int		index;
	int		i;
	int		ret;

	ret = 1;
	fd = 0;
	index = 0;
	i = -1;
	if ((ssl->to_hash = malloc(sizeof(char *) * (MAX_FILES + 1))) == NULL)
		return (EXIT_HELP);
	if (!isatty(fd) && file_str(fd, &ssl->to_hash[index]) > 0 && ++ssl->
			size_printed)
		++index;
	ssl->c_stdin = index;
	while (ssl->filenames[++i] != NULL && ++ssl->size_printed)
	{
		if ((fd = open(ssl->filenames[i], O_RDONLY)) < 0)
			ssl->to_hash[index++] = NULL;
		else
			ret = file_str(fd, &ssl->to_hash[index++]);
	}
	ssl->to_hash[index] = NULL;
	return (0);
}
